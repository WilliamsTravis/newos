// Practicing reading attributes of file
#include <iostream>
#include <netcdfcpp.h>

using namespace std;

const char* FNAME = "/home/travis/github/Drought-Index-Portal/data/"
                    "droughtindices/netcdfs/tdmean.nc";
static const int NC_ERR = 2;

int get_dims(const char* variable, int* ntime, int* nlat, int* nlon)
{
    // Open  file
    NcFile file(FNAME, NcFile::ReadOnly);
    if (!file.is_valid())
        return NC_ERR;

    // Get variable object pointer?
    NcVar *ncvar = file.get_var(variable);

    // Get each dimension object?
    NcDim *time = ncvar->get_dim(0);
    NcDim *lat = ncvar->get_dim(1);
    NcDim *lon = ncvar->get_dim(2);

    // Get each dimension size?
    *ntime = time->size();
    *nlat = lat->size();
    *nlon = lon->size();

    return 0;
}

int print_attrs()
{
    // Open  file
    NcFile file(FNAME, NcFile::ReadOnly);
    if (!file.is_valid())
        return NC_ERR;

    // Print global attributes
    int natts = file.num_atts();
    cout << "Global Attributes:\n";
    for (int i = 0; i < natts; i++){
        NcAtt *a = file.get_att(i);
        NcToken aname = a->name();
        NcType atype = a->type();
        char *avalue = a->as_string(0);
        cout << "  " << aname << ": " << avalue << endl;
    }

    return 0;
}

int print_vars()
{
    // Open  file
    NcFile file(FNAME, NcFile::ReadOnly);
    if (!file.is_valid())
        return NC_ERR;

    // Print dimensions of each variable
    int nvars = file.num_vars();
    cout << FNAME << "\n" << "Dimensions:\n"; 
    for (int vi = 0; vi < nvars; vi++){
        NcVar *v = file.get_var(vi);
        NcToken vname = v->name();
        int ndims = v->num_dims();
        cout << "  " << vname << ": " << endl;
        for (int di = 0; di < ndims; di++){
            NcDim *d = v->get_dim(di);
            NcToken dname = d->name();
            long dsize = d->size();
            cout << "     " << dname << ": " << dsize << "\n";
        }
    }

    return 0;
}

int main()
{
    // Create destructor?
    NcError err(NcError::verbose_nonfatal);

    // Print content summary
    print_vars();

    // Get dimesions for variable
    int ntime, nlat, nlon;
    get_dims("value", &ntime, &nlat, &nlon);
    cout << "Building array with the following dimensions (time, lat, lon): ";
    cout << ntime << ", " << nlat << ", " << nlon << endl;

    // Declare an array (dynamically allocating memory to global stack?)
    double* array = new double[ntime * nlat * nlon];

    // This is a 1-D array, so allocating a 3-D array is tricky
    for (int t = 0; t < ntime; t++)
    {
        for (int lt = 0; lt < nlat; lt++)
        {
            for (int ln = 0; ln < nlon; ln++)
            {
                *(array + t*nlat*nlon + lt*)
            }
        }
    }

    delete[] array;

    return 0;
}