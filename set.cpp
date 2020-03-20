#include "set.h"

Set::Set() {
	start = NULL;
	size = 0;
}

Set::Set(int x)
{
	start = new Nod(x, NULL);
	size = 1;
}



Set::Set(Set& l) {
	start =  NULL;
	size = 0;
	Nod* p = l.start;
	while (p != NULL) {
		insert(p->getInfo());
		p = p->getNext();
	}
}

void Set::insert(int x) {
	insertAt(x, size + 1);
}

void Set::print() {
	Nod *p = start;
	while (p != NULL) {
		std::cout << p->getInfo() << " ";
		p = p->getNext();
	}
	std::cout << std::endl;
}

void Set::insertAt(int x, int i) {
    if(has(x))
        return;
	if (start == NULL) {
		start = new Nod(x, NULL);
		size = 1;
		return;
	}
	Nod* p = new Nod(x, NULL);
	if (i == 0) {
		p->setNext(start);
		start = p;
		size++;
		return;
	}
	if (i < 0 || i >= size) {
		Nod *q=start;
        for(int j=2;j<=size;j++)
         q=q->getNext();

        q->setNext(p);
        size++;
        return;
	}

	Nod* o = start;
	for (int j = i; j > 1; j--) {
		o = o->getNext();
	}
	p->setNext(o->getNext());
	o->setNext(p);
	size++;
}

int Set::get(int i) {
	if (i < 0 || i >= size) {
		return -1;
	}
	Nod* p = start;
	for (int j = i; j > 0; j--) {
		p = p->getNext();
	}
	return p->getInfo();
}

unsigned Set::length() {
	return size;
}

void Set::remove(int i) {
	if (i < 0 || i >= size) {
		return;
	}
	Nod* p = start;
	if (i == 0) {
		if (size == 1 || size == 0) {
			start = NULL;
		}
		else {
			start = start->getNext();
			delete p;
		}
	}
	else {
		for (int j = i; j > 1; j--) {
			p = p->getNext();
		}
		Nod* o = p->getNext();
		p->setNext(o->getNext());
		delete o;
	}
	size--;
}

Set::~Set()
{
	Nod *p = start, *o;
	while (p != NULL) {
		o = p;
		p = p->getNext();
		delete o;
	}
	start = NULL;
	size = 0;
}

bool Set::isEmpty() {
	if (size == 0) {
		return true;
	}
	return false;
}

bool Set::has(int x) {
	Nod *p = start;
	while (p != NULL) {
		if (p->getInfo() == x) {
			return true;
		}
		p = p->getNext();
	}
	return false;
}

int Set::operator[](int i)
{
    return get(i);
}

Set Set::operator+(const Set &o)
{
    Set l(*this);
    Nod *p=o.start;
    while(p!=NULL)
    {
        l.insert(p->getInfo());
        p=p->getNext();

    }
    return l;
}

bool Set::operator<(const Set &o)
{
    return this->size<o.size;
}

bool Set::operator>(const Set &o)
{
    return this->size>o.size;
}

void Set::operator*(int i)
{
    Nod *q=start;
    while(q!=NULL)
    {
        q->setInfo(q->getInfo()*i);
        q=q->getNext();}
}


int Set::suma()
{int s;
    Nod *q=start;
     while(q!=NULL)
    {
        s=s+q->getInfo();
        q=q->getNext();}
        return s;
}

Set Set::pare()
{ Nod *q=start;
    Set l;
     while(q!=NULL)
    { if(q->getInfo()%2==0)
    l.insert(q->getInfo());
        q=q->getNext();}
        return l;
}


Set Set::impare()
{ Nod *q=start;
    Set l;
     while(q!=NULL)
    { if(q->getInfo()%2==1)
    l.insert(q->getInfo());
        q=q->getNext();}
return l;
}











