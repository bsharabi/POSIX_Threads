#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <pthread.h>
#include <signal.h>
// #include <bits/stdc++.h>
#include <cstdlib>
#include <thread>
#include <cmath>


#define BUFFSIZE 1024
class Stack
{
public:
    char *data;
    Stack *next;
};
int size = 0;
int listenFd;
int noThread = 0;
int count = 0;
pthread_mutex_t lock;
Stack *my_stack;
pthread_t threadA[100];
int pId, portNo;
socklen_t len; // store size of the address
struct sockaddr_in svrAdd, clntAdd;
std::vector<pthread_t> threadB;
/**
 * @brief create a new element at the top of the stack.
 *
 * @param val :Value to which the inserted element is initialized.
                Member type value_type is the type of the elements in the container.
 * @return A reference to the top element in the stack.
 */
Stack *newNode(char *);
/**
 * @brief Deallocates the space previously allocated by malloc(), calloc(), aligned_alloc(), (since C11) or realloc().

If ptr is a null pointer, the function does nothing.

The behavior is undefined if the value of ptr does not equal a value returned earlier by malloc(), calloc(), realloc(),
 *
 * @param root : A reference to the top element in the stack.
 * @return none.
 */
void free_stack(Stack **);
/**
 * @brief Colloring the text in red color
 * just for fun :)
 * @return none.
 */
void red();
/**
 * @brief Colloring the text in yellow color
 * just for fun :)
 * @return none.
 */
void yellow();
/**
 * @brief Reseting the text color back to default
 * just for fun :)
 * @return none.
 */
void reset();
/**
 * @brief
 *
 * @param signum : number's signal
 * @return non.
 */
void sig_handler(int);
/**
 * @brief Test whether container is empty
Returns whether the stack is empty: i.e. whether its size is zero.

This member function effectively calls member empty of the underlying container object.
 *
 * @param root : root stack
 * @return true if the underlying container's size is 0, false otherwise.
 */
int isEmpty(Stack *);
/**
 * @brief Remove top element
          Removes the element on top of the stack, effectively reducing its size by one.

          The element removed is the latest element inserted into the stack, whose value can be retrieved by calling member stack::top.

          This calls the removed element's destructor.

          This member function effectively calls the member function pop_back of the underlying container object.
 *
 * @param root : ref root stack
 * @return A reference to the top element in the stack.
 */
Stack *pop(Stack **);
/**
 * @brief Inserts a new element at the top of the stack, above its current top element. The content of this new element is initialized to a copy of val.

    This member function effectively calls the member function push_back of the underlying container object.
 *
 * @param root : ref root stack
 * @param val :Value to which the inserted element is initialized.
                Member type value_type is the type of the elements in the container.
 * @return none
 */
void push(Stack **, char *);
/**
 * @brief Returns a reference to the top element in the stack.

    Since stacks are last-in first-out containers, the top element is the last element inserted into the stack.

    This member function effectively calls member back of the underlying container object.
 *
 * @param root : root stack
 * @return A reference to the top element in the stack.
 */
char *top(Stack *);

/**
 * @brief Connecting the client inputes : push/pop/top
 * Checking if the input is valid
 * If no -> throiwng an error
 * If yes -> dealing with the input in the needed way
 * @return void* 
 */
void *task1(void *);

/**
 * @brief Initiallize the server side
 * @return int = 1 on success, 0 on failure
 */
int server(int argc, char *argv[]);