#pragma once
#include "ElementH.h"
#include "stdafx.h"
template<class T>  Element<T>::Element(T& obj){
	this->object = obj;
	this->next = nullptr;
};

template<class T> T Element<T>::getObject(){
	return  this->object;
};

template<class T> void Element<T>::setObject(T& obj){
	this->object = obj;
	return;
};

template<class T> Element<T>* Element<T>::getNext(){
	return  this->next;
};

template<class T> void Element<T>::setNext(Element<T> * ele){
	this->next = ele;
	return;
};