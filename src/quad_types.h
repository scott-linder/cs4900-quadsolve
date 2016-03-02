/**
 * @file quad_types.h
 * @date Feb 29, 2016
 * @brief Common types for all quadsolver modules.
 */

/**
 * @brief Coefficients to a quadratic equation `a*x^2 + b*x + c = 0`.
 */
typedef struct {
	double a; ///< First coefficient.
	double b; ///< Second coeffeicient.
	double c; ///< Third coefficient.
} Coef;

/**
 * @brief The real roots of a quadratic equation.
 */
typedef struct {
	double x1; ///< First real root (if present).
	double x2; ///< Second real root (if present).
} Root;

#define Logging

