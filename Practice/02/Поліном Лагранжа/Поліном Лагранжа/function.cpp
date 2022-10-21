//#include "function.h"
//#define length 6
//
//double LaGrange(double Array[2][length], double x1)
//{
//	double LaGrangeResult = 0;
//	for (size_t i = 0; i < length; i++)
//	{
//		double Numerator = 1, Denominator = 1, Term = 0;
//		for (size_t j = 0; j < length; j++)
//		{
//			if (j != i)
//			{
//				Numerator *= x1 - Array[0][j];
//				Denominator *= Array[0][i] - Array[0][j];
//			}
//		}
//		Term = Numerator / Denominator * Array[1][i];
//		LaGrangeResult += Term;
//	}
//	return LaGrangeResult;
//}
