#include<iostream>
#include<stdio.h>

using namespace std;


/////////////////////////////////////////////////////////////////////
//Structure Declaration.......... 
////////////////////////////////////////////////////////////////////

template <typename T>
struct SLL_node
{
    T data;
    struct SLL_node *next;
};

template <typename DT>
 struct DLL_node 
 {
    DT data;
	struct DLL_node *next;
	struct DLL_node *prev;
 };

/////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// 1. SINGLY LINEAR LINKED LIST 
///////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
private:
    SLL_node<T> * first;
    int size;
    
public:

       SinglyLL();
  void InsertFirst(T);
  void InsertLast(T); 

  void DeleteFirst();
  void DeleteLast();

  void InsertAtPos(T, int);
  void DeleteAtPos(int);

  void Display();
  int  Count();
  
};

template <class T>
SinglyLL<T> :: SinglyLL()
    {
        first = NULL;
        size = 0;
    }
    
    template <class T>
    void SinglyLL<T> ::  InsertFirst(T no)
    {
        SLL_node<T> *newn = new SLL_node<T>;  // newn = (SSL_PNODE)malloc(sizeof(NODE))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        size++;
    }
    
    template <class T>
    void SinglyLL<T> ::  InsertLast(T no)
    {
        SLL_node<T> *newn = new SLL_node<T>;  // newn = (PNODE)malloc(sizeof(NODE))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            SLL_node<T> *temp = first;
            
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        size++;
    }

    template <class T>
    void SinglyLL<T> ::  DeleteFirst()
    {
        SLL_node<T> *temp = first;
        
        if(first != NULL)
        {
            first = first->next;
            delete temp;
            
            size--;
        }
    }
    
    template <class T>
    void SinglyLL<T> ::  DeleteLast()
    {
        SLL_node<T> *temp = first;
        
        if(first == NULL)
        {
            return;
        }
        else if(first->next == NULL)
        {
            delete first;
            first = NULL;
            size--;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            
            delete temp->next;
            temp->next = NULL;
            size--;
        }
    }
    
    template <class T>
    void SinglyLL<T> ::  Display()
    {
        SLL_node<T> *temp = first;
        
        while(temp!= NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
    template <class T>
    int SinglyLL<T> ::  Count()
    {
        return size;
    }

    template <class T>
    void SinglyLL<T> ::  InsertAtPos(T no, int pos)
       {
           SLL_node<T> *temp = first;
           int i = 0;

           if(pos < 1 || pos > (size + 1))
           {
                  return;
           }

           if(pos == 1)
            {
              InsertFirst(no);
            }         
           else if(pos > (size + 1))
            {
               InsertLast(no);
            } 
           else
            {
               
               SLL_node<T> *newn = new SLL_node<T>;

               newn->data = no;
               newn->next = NULL;

               for (i = 1; i < (pos -1); ++i)
                {
                  temp = temp->next;
                }

              newn->next = temp->next;
              temp->next = newn;

              size++;
            } 
       }

      template <class T>
      void SinglyLL<T> ::  DeleteAtPos(int pos)
       {
          SLL_node<T> *temp = first;
          SLL_node<T> *Targeted = NULL;
           int i = 0;

           if(pos < 1 || pos > (size))
           {
                  return;
           }

           if(pos == 1)
            {
              DeleteFirst();
            }         
           else if(pos > (size))
            {
               DeleteLast();
            } 
           else
            {
               

               for (i = 1; i < (pos -1); ++i)
                {
                  temp = temp->next;
                }
            
              Targeted = temp->next;
              temp->next = Targeted->next;
              delete Targeted;

              size--;
            } 
          
       }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//2. SINGLY CIRCULER LINKED LIST 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 template <class T>
class SinglyCLL
{
private:
                     //characteristics
   SLL_node<T> *first;
   SLL_node<T> *last;
   int size;

public:

        SinglyCLL();
   void InsertFirst(int no);
   void InsertLast(int no);

   void DeleteFirst();
   void DeleteLast();

   void InsertAtPos(int no,int iPos);
   void DeleteAtPos(int iPos);

   void Display();
   int  Count();    
  
};
  template <class T>
 SinglyCLL<T> :: SinglyCLL()
   {
      first = NULL;
      last = NULL;
      size = 0;
   }

 template <class T>
void SinglyCLL<T> ::  InsertFirst(int no)
{
   SLL_node<T> *newn = new SLL_node<T>;
   newn->data = no;
   newn->next = NULL;

   if ((first == NULL)&&(last == NULL))
   {
      first = newn;
      last = newn;
   }
   else
   {
      newn->next = first;
      first = newn;
   }
   last->next = first;
   size++;
}

 template <class T>
void SinglyCLL<T> ::  InsertLast(int no)
{
   SLL_node<T> *newn = new SLL_node<T>;
   newn->next = NULL;
   newn->data = no;

  if ((first == NULL)&&(last == NULL))
   {
      first = newn;
      last = newn;
   }
        else
       {

         last->next = newn;
          last = newn;
       }
   last->next = first;
    size ++;
}

 template <class T>
void SinglyCLL<T> :: InsertAtPos(int no, int iPos)
{

        SLL_node<T> *newn= new SLL_node<T>;

        newn->data = no;
        newn->next = NULL;

        SLL_node<T> *temp = first;

    if((iPos < 1) || (iPos > size+1))
    {
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == size +1)
    {
        InsertLast(no);
    }
    else
    {
        for(int i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }
        
        newn->next = temp->next;
        temp->next = newn;
       
    }

   last->next = first;
    size ++;
}


 template <class T>
void SinglyCLL<T> ::  DeleteFirst()
{
   if ((first == NULL)&&(last == NULL))
   {
      return ;
   }
   else if (first == last)
   {
      delete first;
      first = NULL;
      last =  NULL;
   }
   else
   {
      first = first->next;
      delete last->next;
   }
   last->next = first;
   size--; 
}

 template <class T>
void SinglyCLL<T> ::  DeleteLast()
{
   SLL_node<T> *temp = NULL;
   temp = first;

    if ((first == NULL)&&(last == NULL))
   {
      return;
   }
   else if (size == 1)
   {
      delete last;
      first = NULL;
      last = NULL;
   }

   else
   {
     while(temp->next != last)
     {
         temp = temp->next;
     }

     delete temp->next;
     last = temp;
   }
   last->next=first;
   size--;
   

}

 template <class T>
void SinglyCLL<T> :: DeleteAtPos(int iPos)
{ 
   SLL_node<T> *temp = first;
   SLL_node<T> *targeted = NULL;

   
   if (iPos == 1)
   {
      DeleteFirst();
   }
   else if (iPos == size)
   {
      DeleteLast();
   }
   else
   {
      for (int i = 1;  i < iPos-1;  i++)
      {
         temp = temp-> next;
      }

      targeted = temp->next;
      temp->next = targeted->next;
      delete targeted;

   size --;

   }
   last->next = first;
}

 template <class T>
void SinglyCLL<T> ::  Display()
{
   do
   {
      cout<<"|"<<first->data<<"|";
      first = first->next;

   } while(first != last->next);

   cout<<"\n";

}

 template <class T>
int SinglyCLL<T> ::  Count()
{
   return size;
}


/////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
//3. DOUBLY LINEAR LINKED LIST
///////////////////////////////////////////////////////////////

template <class DT>
class DoublyLLL
 {
	private :
	   DLL_node<DT> *first;
	   DLL_node<DT> * last;
	   int size;

	public :

	        DoublyLLL();
	   void InsertFirst(DT iNo);
	   void InsertLast(DT iNo);

	   void DeleteFirst();
	   void DeleteLast();

	   void InsertAtPos(DT iNo,int iPos);
	   void DeleteAtPos(int iPos);

	   void Display();
       int  Count();
 };

  template <class DT>
  DoublyLLL<DT> :: DoublyLLL()
	     {
            first = NULL;
			size = 0;
	     }

    template <class DT>
	   void DoublyLLL<DT> :: InsertFirst(DT iNo)
	    {
            DLL_node<DT> *newn = new DLL_node<DT> ;

			newn->data = iNo;
			newn->next = NULL;
			newn->prev = NULL;

			if((first == NULL))
			  {
                 first = newn;
			  }
			else
			  {
				  newn->next = first;
				  first = newn;
				  newn->prev = NULL;				  
			  }  
		   size++;	  
		}

       template <class DT>	
	   void DoublyLLL<DT> :: InsertLast(DT iNo)
	    { 
			DLL_node<DT> * newn = new DLL_node<DT> ;
			DLL_node<DT> * temp = first;

			newn -> data = iNo;
			newn -> next = NULL;
			newn -> prev = NULL;

            if((first == NULL))
			  {
				  first = newn;
			  }
			else
			  {

				  while(temp->next != NULL)
				    {
						temp = temp->next;
					}
				 temp->next = newn;	
			     newn->prev = temp;		
				 newn->next = NULL;		
			  }  
		   size++;	  
		}	

       template <class DT>
	   void DoublyLLL<DT> :: DeleteFirst()
		 {
			
            if((first == NULL))
			 {
                return;
			 }
			if((first->next == NULL))
			 {
				 delete first;
				 first = NULL;
			 } 
			else
			 {
                first = first->next;
				delete first->prev;
				first -> prev = NULL;
			 } 	 
           size--;
		 }

       template <class DT>  	 	 
	   void DoublyLLL<DT> :: DeleteLast()
	     {
			 DLL_node<DT> *temp = first;
             if((first == NULL))
			  {
				  return;
			  }

			 if((first->next == NULL))
			  {
				 delete first;
				 first = NULL;  
			  } 
			 else
			  {
				  while(temp->next->next != NULL)
				   {
					   temp = temp->next;
				   }   
				delete temp->next;
				temp->next = NULL; 	 
			  } 
			size--;  
		 }	

        template <class DT>
		void DoublyLLL<DT> :: InsertAtPos(DT iNo,int iPos)
	     {
			 DLL_node<DT> *newn = new DLL_node<DT>;
			 DLL_node<DT> * temp = first;

			 int i = 0;

			 if((iPos < 1) || (iPos > size + 1))
			  {
                return;
			  }
			 if(iPos == 1)
			  {
                InsertFirst(iNo);
			  } 
			 else if(iPos == (size+1)) 
			  {
                InsertLast(iNo);
			  } 
			 else
			  {
                  newn -> data = iNo;
				  newn -> next = NULL;
				  newn -> prev = NULL;

				  for(i = 1; i <= iPos - 1; i++)
				   {
					   temp = temp -> next;
				   }
                 newn->next   = temp->next;
				 newn -> prev = temp;
				 temp->next = newn;
			  }  
			size++;  
		 }	
  
	   template <class DT>
	   void DoublyLLL<DT> :: DeleteAtPos(int iPos)
	     {
			 DLL_node<DT> *temp = first;
			 DLL_node<DT> *Target = NULL;
			 int i = 0;

			 if((iPos < 1) || (iPos > size))
			  {
                return;
			  }
			 if(iPos == 1)
			  {
                DeleteFirst();
			  } 
			 else if(iPos == (size+1)) 
			  {
                DeleteLast();
			  } 
			 else
			  {
                for(i = 0; i < iPos-1; i++)
				 {
					 temp = temp -> next;
				 }
				Target = temp->next;
				temp->next = temp->next->next;
			    temp->next->prev = temp;
				delete Target;
			  }
			size--;  
		 }
       
       template <class DT>
	   void DoublyLLL<DT> :: Display()
	     {
			 DLL_node<DT> *temp = first;

			 while(temp != NULL)
			  {
				  cout<<"|"<<temp->data<<"|->";
                  temp = temp->next;
			  }
			cout<<"NULL\n";  
		 }	 
       
       template <class DT>
	   int DoublyLLL<DT> ::  Count()
	     {
		    return size;
		 }	


////////////////////////////////////////////////////////////////
//4.DOUBLY CIRCULER LINKED LIST........
//////////////////////////////////////////////////////////////////

template <class DT>
class DoublyCL
{
private:
    DLL_node<DT> * first;
    DLL_node<DT> * last;
    int size;
    
public:
   
    DoublyCL();
    void Display();
    int Count();
    void InsertFirst(DT no);
    void InsertLast(DT no);
    void InsertAtPos(DT no , int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
};

// Return_Value Class_Name :: Fnuction_Name(Parameters)

template <class DT>
DoublyCL<DT> :: DoublyCL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }
    
template <class DT>
void DoublyCL<DT> :: InsertFirst(DT no)
{
    DLL_node<DT> * newn = new DLL_node<DT> ;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}

template <class DT>
void DoublyCL<DT> :: InsertLast(DT no)
{
    DLL_node<DT> * newn = new DLL_node<DT> ;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}

template <class DT>
void DoublyCL<DT> :: Display()
{
    DLL_node<DT> * temp = first;
    
    for(int i = 1; i <= size; i++)
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class DT>
int DoublyCL<DT> :: Count()
{
    return size;
}

template <class DT>
void DoublyCL<DT> :: DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

template <class DT>
void DoublyCL<DT> :: DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        last = last -> prev;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

template <class DT>
void DoublyCL<DT> :: InsertAtPos(DT no, int ipos)
{
    if((ipos < 1) || (ipos > size+1))
    {
        return;
    }
    
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == size +1)
    {
        InsertLast(no);
    }
    else
    {
        DLL_node<DT> * newn= new DLL_node<DT>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        
        DLL_node<DT> * temp = first;
        
        for(int i = 1; i < ipos -1; i++)
        {
            temp = temp -> next;
        }
        
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        size++;
    }
}

template <class DT>
void DoublyCL<DT> :: DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > size))
    {
        return;
    }
    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else
    {
        DLL_node<DT> * temp = first;
        
        for(int i = 1; i < ipos -1 ; i ++)
        {
            temp = temp -> next;
        }
       
        temp -> next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
        size--;
    }
}



///////////////////////////////////////////////////////////////////////////
// 5.STACK
///////////////////////////////////////////////////////////////////////////


template <class T>
class Stack     // Singly Linear Linked List
{
private:
     SLL_node<T> * first;
     int size;
    
public:
    
    Stack();
    void push(T);
    int pop();
    void Display();
    int Count();
};

  template <class T>
  Stack<T> :: Stack()
    {
        first = NULL;
        size = 0;
    }
    
   
   template <class T>
   void  Stack<T> :: push(T no)   // InsertFirst()
    {   
        SLL_node<T> *newn = new SLL_node<T>;

        newn -> data = no;
        newn -> next = NULL;

        if(first == NULL)
          {
             first = newn;
          }
        else
          {
              newn->next = first;
              first = newn;
          }  
        size++;  
    }

    template <class T>
    int  Stack<T> :: pop()   // DeleteFirst()
    {
        SLL_node<T> *temp = first;
        int iValue = first->data;

        if(first == NULL)
          {
              return 0;
          }
        if(first -> next == NULL)
          {
            delete first;
            first = NULL;
          } 
        else 
          {
              first = first->next;
              delete temp;
          }
        size--;  
        return iValue;
    }
    

    template <class T>
    void  Stack<T> :: Display()
    {
       SLL_node<T> *temp = first;

        while(temp != NULL)
         {
             cout<<"|"<<temp->data<<"|\n";
             temp = temp->next;
         }
       cout<<"NULL";  
    }
    
    template <class T>
    int  Stack<T> :: Count()
    {
        return size;
    }


/////////////////////////////////////////////////////////////////////////
// 6.QUEUE
///////////////////////////////////////////////////////////////////////////

template <class T>
class Queue     
{
private:
    SLL_node<T> *first;
    int size;
    
public:

    Queue();
    void Enqueue(T);
    int  Dequeue();
    void Display();
    int  Count(); 
};

template <class T>
 Queue<T> :: Queue()
    {
        first = NULL;
        size = 0;
    }

    template <class T>
    void Queue<T> :: Enqueue(T no)   // InsertLast()
    {
        SLL_node<T> *temp = first;
        SLL_node<T> *newn = new SLL_node<T>;

        newn->data = no;
        newn->next = NULL; 

        if(first == NULL)
         {
           first = newn;
         }
        else
         {
             while(temp->next != NULL)
              {
                  temp = temp->next;
              }
            temp->next = newn;  
         } 
        size++; 
    }
    
    template <class T>
    int Queue<T> :: Dequeue()   // DeleteFirst()
    {
        SLL_node<T> *temp = first;

        int iValue = first -> data;
         if(first == NULL)
          {
              return 0;
          }
         else 
          {
             first = first->next;
             delete temp;
          } 
       return iValue; 
       size--;  
    }
    
    template <class T>
    void Queue<T> :: Display()
    {
        SLL_node<T> *temp = first;

       while(temp != NULL)
         {
             cout<<"|"<<temp->data<<"|->";
             temp = temp->next;
         }
       cout<<"NULL\n"; 
    }
    
    template <class T>
    int Queue<T> :: Count()
    {
        return size;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
 
 
 ////////////////////////////////////////////////////////////////////////////
 // TEST CASES FOR SINGLI LINEAR LINKED LIST
 ///////////////////////////////////////////////////////////////////////////

  cout<<"TEST CASES FOR SINGLEY CIRCULER LINKED LIST\n";
    int iRet = 0;
   
    SinglyLL<int> obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    
    obj.InsertLast(101);
    obj.InsertLast(111);

    obj.InsertAtPos(512,3);
    
    obj.Display();
    
    iRet = obj.Count();
    cout<<"Number of elemensts are : "<<iRet<<"\n";
    
   
 /////////////////////////////////////////////////////////////////////////////
 // TEST CASES FOR SINGLI CIRCULER LINKED LIST
 /////////////////////////////////////////////////////////////////////////// 
  
   cout<<"TEST CASES FOR SINGLEY CIRCULER LINKED LIST\n";
  int iRets = 0;
   SinglyCLL<int> sObj;

     sObj.InsertFirst(101);
     sObj.InsertFirst(51);
     sObj.InsertFirst(21);

     sObj.Display();

     sObj.InsertAtPos(31,2);

     sObj.Display();

     sObj.DeleteAtPos(2);

     sObj.Display();

     sObj.DeleteFirst();
     sObj.DeleteLast();
  
     sObj.Display();

     iRets = sObj.Count();

    cout<<"the size is : "<<iRets<<"\n ";

    
 ////////////////////////////////////////////////////////////////////////////
 // TEST CASES FOR DOUBLY LINEAR LINKED LIST
 ///////////////////////////////////////////////////////////////////////////

 cout<<"TEST CASES FOR DOUBLY LINEAR LINKED LIST\n";
     int iRetD = 0;
    DoublyLLL<int> dObj;  
  
    dObj.InsertFirst(101);
	dObj.InsertFirst(51);
	dObj.InsertFirst(21);
	dObj.InsertFirst(10);

	dObj.InsertFirst(201);
	dObj.Display();

	dObj.InsertAtPos(31,3);
	dObj.Display();

	dObj.DeleteFirst();
	dObj.Display();

    dObj.DeleteLast();
	dObj.Display();

	dObj.DeleteAtPos(2);
	dObj.Display();

	iRetD = dObj.Count();

	cout<<"The Size of Linked list is :"<<iRetD<<"\n ";

   
 /////////////////////////////////////////////////////////////////////////////
 // TEST CASES FOR DOUBLY CIRCULER LINKED LIST
 ///////////////////////////////////////////////////////////////////////////

 cout<<"TEST CASES FOR DOUBLY CIRCULER LINKED LIST\n";

int iretD = 0;
     
     DoublyCL<char> Dobj;
    
    Dobj.InsertFirst('O');
    Dobj.InsertFirst('M');
    
    Dobj.InsertLast('K');
    Dobj.InsertLast('R');
    
    Dobj.InsertAtPos('O',3);
    Dobj.Display();
    
    iretD = Dobj.Count();
    cout<<"Number of elements are : "<< iretD<<"\n";
    
    Dobj.DeleteAtPos(3);
    Dobj.DeleteFirst();
    Dobj.DeleteLast();
    
    Dobj.Display();

     iretD = Dobj.Count();
    cout<<"Number of elements are : "<< iretD<<"\n";


 ////////////////////////////////////////////////////////////////////////////
 // TEST CASES FOR STACK.....
 ///////////////////////////////////////////////////////////////////////////

cout<<"TEST CASES FOR STACK\n";

    int sRet = 0;
    Stack  <float> stkobj;
   
    stkobj.push(10);
    stkobj.push(20);
    stkobj.push(30);
    stkobj.push(40);

    stkobj.Display();
    stkobj.Count();

    sRet = stkobj.pop();

    cout<<"the POP element is : "<< sRet<<"\n";


   
 ////////////////////////////////////////////////////////////////////////////
 // TEST CASES FOR QUEUE.....
 ///////////////////////////////////////////////////////////////////////////


cout<<"TEST CASES FOR QUEUE\n";

    int iretQ = 0;
  
     Queue <double> Qobj;
    
    Qobj.Enqueue(11);
    Qobj.Enqueue(21);
    Qobj.Enqueue(51);
    Qobj.Enqueue(101);
    
    iretQ = Qobj.Dequeue();       // 11
    cout<<iretQ;                     // 11
    
    Qobj.Display();          // 11       21          51
    iretQ = Qobj.Count();     // 3
    
    cout<<"Size of queue is : "<<iretQ<<"\n";        // 3*/

    

    return 0;
   
}