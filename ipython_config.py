# -*- coding: utf-8 -*-
"""
Configure ipython to recognize aliases.

Created on Wed Jun 10 16:00:02 2020

@author: twillia2
"""

def startup():
    """Create magic aliases and bookmarks from bash aliases."""
    import os

    from IPython import get_ipython 

    # Create interactive shell and alias manager objects
    ip = get_ipython()
    manager = ip.alias_manager

    # Read in bash alias file
    alias_path = os.path.expanduser("~/.bashrc")
    lines = open(alias_path).readlines()

    # Check each line in the file for an alias and get its command
    for line in lines:
        if line.startswith("alias"):
            line = ' '.join(line.split()[1:])
            split = line.find('=')
            alias = line[:split]
            cmd = line[split + 1:][1:-1]

            # Use alias magic if the command does not change directories only
            if "cd " not in cmd or len(cmd.split()) > 2:
                manager.soft_define_alias(alias, cmd)

            # Otherwise, use bookmarks
            else:
                loc = cmd.replace("cd ", "")
                ip.magic("bookmark {} {}".format(alias, loc))


def magic_editor():
    """Use magic to open file in editor."""
    from IPython import TerminalInteractiveShell

    TerminalInteractiveShell.editor
                

if __name__ == "__main__":
    startup()
