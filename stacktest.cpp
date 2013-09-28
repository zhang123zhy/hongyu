/* stack
*  2013.9.24
*  author zhanghongyu
*/

#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

typedef struct{
    int *elems;
    int loglength;
    int alloclength;
}stack;

void StackNew(stack *s);
void StackPush(stack *s,int value);
int stackPop(stack *s);
void StackDispose(stack *s);

void StackNew(stack *s)
{
    s->loglength = 0;
    s->alloclength = 4;
    s->elems =(int*)malloc(4*sizeof(int));
    assert(s->elems != NULL);
}

void StackDispose(stack *s)
{
    free(s->elems);
}

void StackPush(stack *s, int value)
{
    if(s->loglength == s->alloclength){
    s->alloclength *=2;
    s->elems = (int*)realloc(s->elems, s->alloclength*sizeof(int));
    assert(s->elems != NULL);  
    }
    s->elems[s->loglength] = value;
    s->loglength++;
}

int StackPop(stack *s)
{
    assert(s->loglength > 0);
    s->loglength--;
    return s->elems[s->loglength];
}
int main()
{
    stack s;
    StackNew(&s);
    for (int i = 0; i < 10; i++)
    {
    StackPush(&s, i);
    }
    
    for (int i = 0; i < 10; i++)
    {
    cout << s.elems[i];
    }
    cout << "\n" ;    
    for (int i = 0; i<10; i++)
    {
    cout << StackPop(&s);
    }
    StackDispose(&s);
    return 0;
}
