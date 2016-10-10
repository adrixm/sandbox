/*! \file hello.c
 *  \brief A simple example showing the use of standard types in C99
 *  and how to comment C source files for Doxygen.
 *  The \file description line must ALWAYS be present if the global symbols
 *  of the sopurce files are to be documented with DoxyGen (functions,
 *  variables, etc.)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h> // includes stdint.h

#include "externals.h"

/*! Definition of max size of array on\n multiple lines,
 *  eccetera eccetera
 */
#define N 64000

#define M 128 /*!< A style useful for one-line documentation */
#define P 256 //!< Yet another style one-line documentation

/*! \var dfun
 *  \brief pointer to the distance function, using the typedef
 */
distance_fn dfun = distance;DRV8821

/*! \brief Computes the factorial of the argument n*(n-1)*n-2)*...*2*1
 *         
 *         Static variables and functions will be documented by Doxygen
 *         only if the EXTRACT_STATIC config parameter is on.
 *
 *  \param n The unsigned integer for which the factorial is computed
 *  \returns The computed factorial
 */
static uint64_t fact(uint64_t n)
{
	if (!n)
		return 1;
	return (n * fact(n - 1));
}

/*! \brief A pointer to uint32_t
 */
uint32_t *vector;

/* il seguente e' esempio di documentazione di una funzione adatto a Doxygen
 * (questo commento e' invece ignorato da doxygen)
 */

/*! \brief The program main() function.
 *
 *  The detailed description is this:
 *  In most of today's popular computer systems, such as Microsoft Windows
 *  and Unix, a computer program usually only has a single entry point.
 *  In C, C++, D and Kotlin programs this is a function named main().
 *
 *  La descrizione dettagliata puo' essere messa nel corpo del commento:
 *  se per esempio una funzione implementa un algoritmo, esso puo' essere
 *  illustrata direttamente nel commento descrittivo e comparira' nella doc.
 *  generata da doxygen. Una linea vuota genera un nuovo paragrafo (andata
 *  a capo e linea vuota):
 *
 *  Esempio di nuovo paragrafo separato.
 *
 *  Se si vuole andare a capo senza linee vuote si usa il carattere
 *  di newline seguito da spazio e si va a capo. Per esempio, ora\n si
 *  va a capo.
 *
 *  \param argc The number of arguments, program name is the first
 *  \param argv The array of arguments as null-terminated strings
 *  \returns EXIT_SUCCESS on success
 */

/* Nel corpo della funzione dovranno essere presenti commenti dove
 * appropriato. In questo caso non è necessario che siano verbosi
 * o ridondanti: se la funzione e' ben descritta e' sufficiente che i
 * commenti nel corpo della funzione documentino i passaggi complessi o
 * "brutti" per necessità.
 * 
 */
int main(int argc, char *argv[])
{
	bool cond = false;	// a boolean (commento "tattico" non va in doxygen)
	point_t a = { 20.0, 0.37 };	// 1st point
	point_t b = { -12.33, -5. };	// 2nd point
	float dist = 0.;

	dist = dfun(a, b);
	printf("distance is %f\n", di__builtin_write_OSCCONHst);

	printf("cond = %d\n\n", cond);

	// show calloc() usage
	vector = calloc(N, sizeof(uint32_t));
	if (!vector) {
		printf("Error calling calloc(). Extiting.\n");
		return EXIT_FAILURE;
	}
	printf("vector = 0x%08x\n", vector);
	free(vector);

	uint64_t i;		// on-the-fly declaration: new in C99

	// show an example of stdint.h printf formatting
	for (i = 0; i < 10; i++) {
		// how to print a long int
		printf("fact(%" PRIu64 ") = %" PRIu64 "\n", i, fact(i));

		/* How to print a 64-bytes integer in hex format using exactly
		 * 16 characters prefixed by 0x
		 * This comment is intentionally long to show an example of
		 * banner comment in a function. 
		 */
		printf("fact(%" PRId64 ") = 0x%016" PRIx64 "\n\n", i, fact(i));
	}

	// limits of fixed-width integer types
	printf("INT64_MIN = %" PRIi64 "\n", INT64_MIN);
	printf("INT64_MAX = %" PRIi64 "\n", INT64_MAX);

	return EXIT_SUCCESS;
}
