# Knowledge of using C extensions in Python code

**Problem Definition**

Understand how to use c extensions in python. 
Write one program to handle c extension in python code. 

**What is "extension"?**

Any code that you write using any compiled language like C, C++, or Java can be integrated or imported into another 
Python script. This code is considered as an "extension."  

**Key Points**

- The Header File Python.h : You need include Python.h header file in your C source file, which gives you access to the 
internal Python API used to hook your module into the interpreter. 

- C function signatures:

    1.         static PyObject *MyFunction( PyObject *self, PyObject *args );

    2.         static PyObject *MyFunctionWithKeywords(PyObject *self,
                                 PyObject *args,
                                 PyObject *kw);

    3.         static PyObject *MyFunctionWithNoArgs( PyObject *self ){
                    /* Do your stuff here. */
                    Py_RETURN_NONE;
                }
              
- The Method Mapping Table : 
                
                struct PyMethodDef {
                        char *ml_name; # name of the function as the Python interpreter presents when it is used in Python programs
                        PyCFunction ml_meth; # address to the function
                        int ml_flags; # tells the interpreter which of the three signatures ml_meth is using
                        char *ml_doc; # docstring for the function
                };

- The Initialization Function : 

                PyMODINIT_FUNC initModule() {
                    Py_InitModule3(func, module_methods, "docstring...");
                }
                
                - func − This is the function to be exported.

                - module_methods − This is the mapping table name defined above.

                - docstring − This is the comment you want to give in your extension.

