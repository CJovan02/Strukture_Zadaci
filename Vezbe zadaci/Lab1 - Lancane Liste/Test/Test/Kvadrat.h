#pragma once
class Kvadrat
{
private:
	float a, povrsina;
public:
	Kvadrat(float a) { this->a = a; povrsina = a * a; }

	void Print();

	float GetA() { return a; };
};

