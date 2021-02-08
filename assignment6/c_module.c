#include <Python.h>

int armstrong(int originalNum){
int num = originalNum;
int result =0, remainder = 0;
while (originalNum != 0) {
       // remainder contains the last digit
        remainder = originalNum % 10;

       result += remainder * remainder * remainder;

       // removing last digit from the orignal number
       originalNum /= 10;
    }
    if (result == num)
        printf("%d is an Armstrong number.", num);

    else
        printf("%d is not an Armstrong number.", num);

    return 0;
}

// Function 1: A simple 'fib' function
static PyObject* armStrong(PyObject* self, PyObject* args)
{
    int n;
    if(!PyArg_ParseTuple(args,"i",&n))
            return NULL;
    return Py_BuildValue("i",armstrong(n));
}

static PyMethodDef myMethods[] = {
    { "armStrong", armStrong, METH_VARARGS, "armStrong number series" },
    { NULL, NULL, 0, NULL }
};

// Our Module Definition struct
static struct PyModuleDef c_module = {
    PyModuleDef_HEAD_INIT,
    "c_module",
    "Test Module",
    -1,
    myMethods
};

// Initializes our module using our above struct
PyMODINIT_FUNC PyInit_c_module(void)
{
    return PyModule_Create(&c_module);
}