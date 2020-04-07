#pragma once
#include<vector>
#include<iostream>
using namespace std;

template<class T, int CAP = 10>class RepoT {
private:
	vector<T> l;
	int size;

public:

	RepoT();
	RepoT(const RepoT<T, CAP>&);
	~RepoT();

	RepoT<T, CAP>& operator=(const RepoT<T, CAP>& aux);
	void deleteElem(int);
	vector<T> getAll();
	void addElem(T);
	void setSize(int a);
	//T getAll();
	int getSize();
	//friend ostream& operator<<(ostream &, const RepoT &);
};

template<class T, int CAP>RepoT<T, CAP>::RepoT() {
	this->size = 0;
	//this->addElem = {};
};

template<class T, int CAP>RepoT<T, CAP>::RepoT(const RepoT<T, CAP>& v) {

	this->size = v.size;
	//this->elem=v.elem;
	//vector<T>::iterator it=v.begin();
	//while(it!=v.end())
	this->l.reserve(this->size);
	for (int i = 0; i < this->size; i++)
	{

		this->l.push_back(v[i]);
	};
};

template <class T, int CAP> vector<T> RepoT<T, CAP>::getAll() {
	return this->l;
};

template<class T, int CAP>RepoT<T, CAP>::~RepoT() {

};

template<class T, int CAP>void RepoT<T, CAP>::addElem(T e) {
	if (this->size < CAP)
		this->l.push_back(e);
	else
		cout << "spatiu insuficient..." << endl;
};


template<class T, int CAP>int RepoT<T, CAP>::getSize() {
	return this->l.size();
};

template <class T, int CAP> void RepoT<T, CAP>::deleteElem(int pos) {
	int aux = l.size();
	this->l[pos] = this->l[--aux];
};

template<class T, int CAP>void RepoT<T, CAP>::setSize(int a) {
	this->size = a;
};

template<class T, int CAP>RepoT<T, CAP>& RepoT<T, CAP>::operator=(const RepoT<T, CAP>& r) {
	if (this != &r) {
		this->size = r.size;
		for (int i = 0; i < this->size; i++) {
			this->l.push_back(r.l[i]);
		}
	};
	return *this;
};
/*

template<class T, int CAP>T RepoT<T, CAP>::getAll() {
return this->l;
}

template<class T, int CAP>ostream& RepoT<T, CAP>::operator<<(ostream &os, const RepoT<T,CAP> &f) {
os << f.toString() << endl;
return os;
}*/


