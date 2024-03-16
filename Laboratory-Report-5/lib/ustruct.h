#ifndef USTRUCT_H
#define USTRUCT_H

template <class T>
struct TNode
{
    T data;      // информационное поле
    TNode *next; // адресное поле
};

#endif // USTRUCT_H
