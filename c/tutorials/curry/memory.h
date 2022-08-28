#include <iostream>
#include <fstream>

using namespace std;

void memory()
{
    int tsize = 0, resident = 0, share = 0;
    ifsteram buffer("/proc/self/statm");
    buffer >> tsize >> resident >> share;
    buffer.close();

    // In case x86-64 is configured to use 2MB pages
    long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024;

    double rss = resident * page_size_kb;
    double shared_mem = share * page_size_kb;

    cout << "RSS: " << rss << " kb\n";
    cout << "Shared Memory: " << shared_mem << " kb\n";
    cout << "Private Memory: " << rss - shared_mem << " kb\n";

}

int main()
{
    memory();
    return 0;
}