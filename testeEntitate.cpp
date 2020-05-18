#include "testeEntitate.h"


#include <assert.h>

void testeEntitate::test_nume()
{
	ResursaEconomica re = ResursaEconomica();
	re.setNume("Bani");
	assert(re.getNume() == "Bani");
}

void testeEntitate::test_valoare()
{
	ResursaEconomica re = ResursaEconomica();
	re.setValoare(15);
	assert(re.getValoare() == 15);
}

void testeEntitate::test_data()
{
	ResursaEconomica re = ResursaEconomica();
	re.setDate(Date(13, 2, 2016));
	assert(re.getDate() == Date(13, 2, 2016));
}

void testeEntitate::run()
{
	test_nume();
	test_valoare();
	test_data();
}