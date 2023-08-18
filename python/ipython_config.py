# -*- coding: utf-8 -*-
"""
Configure ipython to recognize aliases.

Created on Wed Jun 10 16:00:02 2020

@author: twillia2
"""
try:
    import matplotlib.pyplot as plt
except ImportError:
    pass



def startup():
    """Create magic aliases and bookmarks from bash aliases."""
    import os

    from IPython import get_ipython

    # Indicate that it's being run
    print(f"Running startup script: {__file__}")

    # Use simple pager
    os.environ["PAGER"] = "cat"

    # Create interactive shell and alias manager objects
    ip = get_ipython()
    manager = ip.alias_manager

    # Read in bash alias file
    alias_path = os.path.expanduser("~/.bash_aliases")
    lines = open(alias_path).readlines()

    # Check each line in the file for an alias and get its command
    for line in lines:
        if line.startswith("alias"):
            line = " ".join(line.split()[1:])
            split = line.find("=")
            alias = line[:split]
            cmd = line[split + 1:][1:-1]

            # Use alias magic if the command does not change directories only
            if not cmd.startswith("cd ") or len(cmd.split()) > 2:
                manager.soft_define_alias(alias, cmd)

            # Otherwise, use bookmarks
            else:
                loc = cmd.replace("cd ", "")
                ip.run_line_magic("bookmark", f"{alias} {loc}")


if __name__ == "__main__":
    startup()
