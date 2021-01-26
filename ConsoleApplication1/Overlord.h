#pragma once

#include "ArcaneWarrior.h"

template <typename T>
class Overlord : public T
{
protected:
	vector<Character*> m_subjects;

public:
	Overlord(string name);
	virtual ~Overlord();
	void lynching(Character* target);
	void setSubjects();
	void setCharacters(vector<Character*> characters);

};

template<typename T>
inline Overlord<T>::Overlord(string name) : T(name), Character(name)
{
	Character::m_hp *= 2;
}

template<typename T>
inline Overlord<T>::~Overlord()
{
}

template<typename T>
inline void Overlord<T>::lynching(Character* target)
{
	cout << Character::m_name << ": Serve your overlord and lynch his ass !" << endl;
	for (int k = 0; k < m_subjects.size(); k++) {
		m_subjects[k]->attack(target);
	}
}

template<typename T>
inline void Overlord<T>::setSubjects()
{
	for (int k = 0; k < Character::m_characters.size(); k++) {
		cout << "hehe" << endl;
		bool isAlly = false;
		for (unsigned int m = 0; m < Character::m_allies.size(); m++) {
			if (Character::m_characters[k] == Character::m_allies[m]) isAlly = true;
		}
		if ((Character::m_characters[k]->getType() == Character::getType()) && isAlly) {
			m_subjects.push_back(Character::m_characters[k]);
		}
	}
}

template<typename T>
inline void Overlord<T>::setCharacters(vector<Character*> characters)
{
	Character::m_characters = characters;
	setSubjects();
}
