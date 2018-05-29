
//provides pointer like behaviour
//copying handle will create a shared alias of the object
//to create a handle the user will pass a fresh dynamically allocated object of the type T
//handle assumes responsibility for deleting the owned object once no handles attached to it
template<class T>
class Handle
{
private:
	T* fPointer;
	int* fCount;

	void addRef();
	void releaseRef();

public:
	Handle(T* aPointer = (T*)0);
	Handle(const Handle<T>& aOtherHandle);
	~Handle();

	Handle& operator=(Handle<T>& aOtherHandle);
	T& operator*();
	T* operator->();
};

//implementation
template <class T>
Handle<T>::Handle(T* aPointer = (T*)0)
{
	fPointer = aPointer;
	fCount = new int;
	*fCount = 1; //shared counter
}

template <class T>
Handle<T>::~Handle()
{
	releaseRef();
}

//incrementing reference count
template <class T>
void Handle<T>::addRef()
{
	++*fCount;
}

//decrement reference count and delete object if it is no longer referenced anywhere
template <class T>
void Handle<T>::releaseRef()
{
	if (--*fCount == 0)
	{
		delete fPointer;
		delete fCount;
	}
}

template <class T>
Handle<T>::Handle(const Handle<T>& aOtherHandle)
{
	fPointer = aOtherHandle.fPointer;
	fCount = aOtherHandle.fCount;
	addRef(); //increment use
}

template <class T>
Handle<T>& Handle<T>::operator=(Handle<T>& aOtherHandle)
{
	if (&aOtherHandle != this)
	{
		aOtherHandle.addRef(); //increment use
		releaseRef(); //release old handle
		fPointer = aOtherHandle.fPointer;
		fCount = aOtherHandle.fCount;
	}
	return *this;
}

template <class T>
T& Handle<T>::operator*()
{
	if (fPointer)
		return *fPointer;
	else
		throw std::runtime_error("Dereference of unbound handle!");
}

template <class T>
T* Handle<T>::operator->()
{
	if (fPointer)
		return fPointer;
	else
		throw std::runtime_error("Access through unbound handle!");
}