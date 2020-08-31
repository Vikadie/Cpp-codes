#include "UnitPtr.h"

UnitPtr::UnitPtr()
{
}

UnitPtr UnitPtr::from(T* rawPointer)
{
	return UnitPtr();
}

UnitPtr::UnitPtr(const UnitPtr& other)
{
}

T& UnitPtr::operator*()
{
	// TODO: insert return statement here
}

T* UnitPtr::operator->() const
{
	return nullptr;
}

UnitPtr& UnitPtr::operator=(const UnitPtr& other)
{
	// TODO: insert return statement here
}

UnitPtr::~UnitPtr()
{
}
