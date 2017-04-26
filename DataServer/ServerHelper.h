#ifndef _SERVER_HELPER_H_
#define _SERVER_HELPER_H_

#include <cstdio>
#include <cstdlib>


template <class T> class List
{
public:

	List();
	void add(T * newT);
	void remove(T * oldT);
	int getCount();
	T * get(int id);


private:

	T ** TList;
	int TCount;

};

template <class T> List<T>::List()
{
	TList = NULL;
	TCount = 0;
	printf("INITED\n");
}

template <class T> void List<T>::add(T * newT)
{
	TList = (T **) realloc(TList, (TCount+1)*sizeof(T*));
	if(TList == NULL)
	{
		printf("MEMORY ERROR !\n");
	}

	TList[TCount] = newT;
	TCount++;
}


template <class T> void List<T>::remove(T * oldT)
{
	for(int i = 0 ; i < TCount ; i++)
	{
		if(TList[i] == oldT)
		{
			memmove( (TList+i   ),
				 	 (TList+i+1 ),
					 (TCount-i-1)*sizeof(T*));
			
			TCount--;
			i--;
		}
	}

	TList = (T **) realloc(TList, TCount*sizeof(T*));
	if(TList == NULL)
	{
		printf("MEMORY ERROR !\n");
	}

}

template <class T> int List<T>::getCount()
{
	return TCount;
}

template <class T> T * List<T>::get(int id)
{
	return TList[id];
}






template <class T> class ListD
{
public:

	ListD();
	void add(T newT);
	void remove(T oldT);
	int getCount();
	T get(int id);
	



private:

	T * TList;
	int TCount;

};

	
template <class T> ListD<T>::ListD()
{
	TList = NULL;
	TCount = 0;
	printf("INITED\n");
}

template <class T> void ListD<T>::add(T newT)
{
	TList = (T *) realloc(TList, (TCount+1)*sizeof(T));
	if(TList == NULL)
	{
		printf("MEMORY ERROR !\n");
	}

	TList[TCount] = newT;
	TCount++;
}


template <class T> void ListD<T>::remove(T oldT)
{
	for(int i = 0 ; i < TCount ; i++)
	{
		if(TList[i] == oldT)
		{
			memmove( (TList+i   ),
				 	 (TList+i+1 ),
					 (TCount-i-1)*sizeof(T));
			
			TCount--;
			i--;
		}
	}

	TList = (T *) realloc(TList, TCount*sizeof(T));
	if(TList == NULL)
	{
		printf("MEMORY ERROR !\n");
	}

}

template <class T> int ListD<T>::getCount()
{
	return TCount;
}

template <class T> T ListD<T>::get(int id)
{
	return TList[id];
}


#endif // _SERVER_HELPER_H_
