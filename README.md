# fortyaml
This is a wrapper for libyaml, the canonical C libarary, utilizing the C to Fortran bindings.  
Fortyaml is inteded to read a yaml file and load it into a c++ dictionary. Also provided are methods to allow the extraction of the data. It is likely that for specific use cases additional methods will need to be developed.

Currently the only functionality not included in the loading of the dictionary is global tags. 
