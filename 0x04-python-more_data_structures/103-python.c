#include <Python.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_python_bytes - Prints some basic info about Python bytes objects
 * @p: PyObject bytes object
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size;
    char *str;
    Py_ssize_t i;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }
    size = PyBytes_Size(p);
    str = PyBytes_AsString(p);
    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", str);
    if (size > 10)
        size = 10;
    else
        size++;
    printf("  first %ld bytes:", size);
    for (i = 0; i < size; i++)
        printf(" %02hhx", str[i]);
    printf("\n");
}

/**
 * print_python_list - Prints some basic info about Python lists
 * @p: PyObject list
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t size = PyList_Size(p);
    Py_ssize_t i;
    PyObject *item;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);
    for (i = 0; i < size; i++)
    {
        item = PyList_GetItem(p, i);
        printf("Element %ld: %s\n", i, item->ob_type->tp_name);
        if (PyBytes_Check(item))
            print_python_bytes(item);
    }
}
