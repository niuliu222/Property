#pragma once

#define PropertyDecare(type, name, init_value) type name = init_value;

#define PropertyGetter(type, name) type Get##name(){return name;}

#define PropertyGetterReference(type, name) const type & Get##name##ConstReference(){return name;}

#define PropertySetter(type, name) void Set##name(const type & _value){name = _value;}


#define PropertyPrivate(type, name, init_value) \
private:\
	PropertyDecare(type, name, init_value)


#define PropertyReadOnly(type, name, init_value) \
	PropertyPrivate(type, name, init_value)\
public:\
	PropertyGetter(type, name)

#define PropertyReadWrite(type, name, init_value) \
	PropertyReadOnly(type, name, init_value)\
public:\
	PropertySetter(type, name)

#define PropertyObjectReadOnly(type, name, init_value) \
	PropertyReadOnly(type, name, init_value)\
public:\
	PropertyGetterReference(type, name)

#define PropertyObjectReadWrite(type, name, init_value) \
	PropertyObjectReadOnly(type, name, init_value)\
public:
	PropertySetter(type, name)