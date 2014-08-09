#include "stdafx.h"
#include "Fraction.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

using namespace Ratio;

namespace FractionTest
{
	[TestClass]
	public ref class FractionUnitTest
	{
	public: 
		[TestMethod]
		void AddOneFraction()
		{
			Fraction f1 (10, 20);
			Assert::AreEqual (1, f1.getNumer ());
			Assert::AreEqual (2, f1.getDenom ());
		}

		[TestMethod]
		void TryCatchTestDenominatorZero()
		{
			try
			{
				Fraction f (1, 0);
				Assert::Fail ("We shouldn't reach this code"); 
			}
			catch (std::exception& err)
			{
				Assert::IsTrue (std::string ("denominator is not valid") == err.what()); 
			}
		}

		[TestMethod]
		void TryCatchTestMinusDenominator()
		{
			try
			{
				Fraction f (1, -10);
				Assert::Fail ("We shouldn't reach this code"); 
			}
			catch (std::exception& err)
			{
				Assert::IsTrue (std::string ("denominator is not valid") == err.what()); 
			}
		}

		[TestMethod]
		void AddFewFractions()
		{
			Fraction f1 (10, 20);
			Assert::AreEqual (1, f1.getNumer ());
			Assert::AreEqual (2, f1.getDenom ());
			Fraction f2 (7, 10);
			Assert::AreEqual (7, f2.getNumer ());
			Assert::AreEqual (10, f2.getDenom ());
			Fraction f3 (45, 9);
			Assert::AreEqual (5, f3.getNumer ());
			Assert::AreEqual (1, f3.getDenom ());
		}

		[TestMethod]
		void SumTwoFractionsWhichDoNotChange()
		{
			Fraction f1 (10, 20);
			Fraction f2 (7, 10);
			Fraction f3 = f1 + f2;
			Assert::AreEqual (6, f3.getNumer ());
			Assert::AreEqual (5, f3.getDenom ());
			Assert::AreEqual (1, f1.getNumer ());
			Assert::AreEqual (2, f1.getDenom ());
			Assert::AreEqual (7, f2.getNumer ());
			Assert::AreEqual (10, f2.getDenom ());
		}

		[TestMethod]
		void SumFewFractions()
		{
			Fraction f1 (10, 20);
			Fraction f2 (7, 10);
			Fraction f3 (1, 3);
			Fraction f4 (6, 2);
			Fraction f5 = f1 + f2 + f3 + f4;
			Assert::AreEqual (68, f5.getNumer ());
			Assert::AreEqual (15, f5.getDenom ());			
		}

		[TestMethod]
		void SumFractionWhichDoesNotChangeWithNumber()
		{
			Fraction f1 (10, 20);
			Fraction f2 = f1 + 5;			
			Assert::AreEqual (11, f2.getNumer ());
			Assert::AreEqual (2, f2.getDenom ());
			Assert::AreEqual (1, f1.getNumer ());
			Assert::AreEqual (2, f1.getDenom ());
		}

		[TestMethod]
		void SumFractionsWithFewNumbers()
		{
			Fraction f1 (10, 20);
			Fraction f2 = f1 + 5 + 8 + 1;			
			Assert::AreEqual (29, f2.getNumer ());
			Assert::AreEqual (2, f2.getDenom ());			
		}

		[TestMethod]
		void SumFractionWithFractionAndNumber()
		{
			Fraction f1 (10, 20);
			Fraction f2 (7, 10);
			Fraction f3 = f1 + f2 + 5;			
			Assert::AreEqual (31, f3.getNumer ());
			Assert::AreEqual (5, f3.getDenom ());			
		}

		[TestMethod]
		void DeductFromFractionFractionWhichDoNotChange()
		{
			Fraction f1 (10, 20);
			Fraction f2 (7, 10);
			Fraction f3 = f1 - f2;
			Assert::AreEqual (-1, f3.getNumer ());
			Assert::AreEqual (5, f3.getDenom ());
			Assert::AreEqual (1, f1.getNumer ());
			Assert::AreEqual (2, f1.getDenom ());
			Assert::AreEqual (7, f2.getNumer ());
			Assert::AreEqual (10, f2.getDenom ());
		}

		[TestMethod]
		void DeductFewFractions()
		{
			Fraction f1 (10, 20);
			Fraction f2 (7, 10);
			Fraction f3 (1, 3);
			Fraction f4 (6, 2);
			Fraction f5 = f1 - f2 - f3 - f4;
			Assert::AreEqual (-53, f5.getNumer ());
			Assert::AreEqual (15, f5.getDenom ());			
		}

		[TestMethod]
		void DeductFromFractionWhichDoesNotChangeNumber()
		{
			Fraction f1 (10, 20);
			Fraction f2 = f1 - 5;			
			Assert::AreEqual (-9, f2.getNumer ());
			Assert::AreEqual (2, f2.getDenom ());
			Assert::AreEqual (1, f1.getNumer ());
			Assert::AreEqual (2, f1.getDenom ());
		}

		[TestMethod]
		void DeductFromFractionsFewNumbers()
		{
			Fraction f1 (10, 20);
			Fraction f2 = f1 - 5 - 8 - 1;			
			Assert::AreEqual (-27, f2.getNumer ());
			Assert::AreEqual (2, f2.getDenom ());			
		}

		[TestMethod]
		void DeductFromFractionFractionAndNumber()
		{
			Fraction f1 (10, 20);
			Fraction f2 (7, 10);
			Fraction f3 = f1 - f2 - 5;			
			Assert::AreEqual (-26, f3.getNumer ());
			Assert::AreEqual (5, f3.getDenom ());			
		}

		[TestMethod]
		void MultiplicationFractionFractionWhichDoNotChange()
		{
			Fraction f1 (10, 20);
			Fraction f2 (7, 10);
			Fraction f3 = f1 * f2;
			Assert::AreEqual (7, f3.getNumer ());
			Assert::AreEqual (20, f3.getDenom ());
			Assert::AreEqual (1, f1.getNumer ());
			Assert::AreEqual (2, f1.getDenom ());
			Assert::AreEqual (7, f2.getNumer ());
			Assert::AreEqual (10, f2.getDenom ());
		}

		[TestMethod]
		void MultiplicationFewFractions()
		{
			Fraction f1 (10, 20);
			Fraction f2 (7, 10);
			Fraction f3 (1, 3);
			Fraction f4 (6, 2);
			Fraction f5 = f1 * f2 * f3 * f4;
			Assert::AreEqual (7, f5.getNumer ());
			Assert::AreEqual (20, f5.getDenom ());			
		}

		[TestMethod]
		void MultiplicationFractionWhichDoesNotChangeAndNumber()
		{
			Fraction f1 (10, 20);
			Fraction f2 = f1 * 5;			
			Assert::AreEqual (5, f2.getNumer ());
			Assert::AreEqual (2, f2.getDenom ());
			Assert::AreEqual (1, f1.getNumer ());
			Assert::AreEqual (2, f1.getDenom ());
		}

		[TestMethod]
		void MultiplicationFractionsAndFewNumbers()
		{
			Fraction f1 (10, 20);
			Fraction f2 = f1 * 5 * 8 * 1;			
			Assert::AreEqual (20, f2.getNumer ());
			Assert::AreEqual (1, f2.getDenom ());			
		}

		[TestMethod]
		void MultiplicationFractionAndFractionAndNumber()
		{
			Fraction f1 (10, 20);
			Fraction f2 (7, 10);
			Fraction f3 = f1 * f2 * 5;			
			Assert::AreEqual (7, f3.getNumer ());
			Assert::AreEqual (4, f3.getDenom ());			
		}

		[TestMethod]
		void DivisionFractionFractionWhichDoNotChange()
		{
			Fraction f1 (10, 20);
			Fraction f2 (7, 10);
			Fraction f3 = f1 / f2;
			Assert::AreEqual (5, f3.getNumer ());
			Assert::AreEqual (7, f3.getDenom ());
			Assert::AreEqual (1, f1.getNumer ());
			Assert::AreEqual (2, f1.getDenom ());
			Assert::AreEqual (7, f2.getNumer ());
			Assert::AreEqual (10, f2.getDenom ());
		}

		[TestMethod]
		void DivisionFewFractions()
		{
			Fraction f1 (10, 20);
			Fraction f2 (7, 10);
			Fraction f3 (1, 3);
			Fraction f4 (6, 2);
			Fraction f5 = f1 / f2 / f3 / f4;
			Assert::AreEqual (5, f5.getNumer ());
			Assert::AreEqual (7, f5.getDenom ());			
		}

		[TestMethod]
		void DivisionFractionWhichDoesNotChangeAndNumber()
		{
			Fraction f1 (10, 20);
			Fraction f2 = f1 / 5;			
			Assert::AreEqual (1, f2.getNumer ());
			Assert::AreEqual (10, f2.getDenom ());
			Assert::AreEqual (1, f1.getNumer ());
			Assert::AreEqual (2, f1.getDenom ());
		}

		[TestMethod]
		void DivisionFractionsAndFewNumbers()
		{
			Fraction f1 (10, 20);
			Fraction f2 = f1 / 5 / 8 / 1;			
			Assert::AreEqual (1, f2.getNumer ());
			Assert::AreEqual (80, f2.getDenom ());			
		}
		[TestMethod]
		void DivisionFractionAndFractionAndNumber()
		{
			Fraction f1 (10, 20);
			Fraction f2 (7, 10);
			Fraction f3 = f1 / f2 / 5;			
			Assert::AreEqual (1, f3.getNumer ());
			Assert::AreEqual (7, f3.getDenom ());			
		}

		[TestMethod]
		void InfoAboutFraction()
		{
			Fraction f1 (10, 20);
			Assert::IsTrue (std::string ("1/2") == f1.FractionInfo());			
		}

		[TestMethod]
		void InfoAboutFractionAfterDivision()
		{
			Fraction f1 (10, 20);
			Fraction f2 (7, 10);
			Fraction f3 = f1 / f2 / 5;			
			Assert::IsTrue (std::string ("1/7") == f3.FractionInfo());			
		}

		[TestMethod]
		void AllOperationsTogether()
		{
			Fraction f1 (10, 20);
			Fraction f2 (7, 10);
			Fraction f3 (1, 3);
			Fraction f4 (6, 2);
			Fraction f5 (3, 5);
			Fraction f6 = f1 * 4 + f2 - 2 - f3 * f4 / f5 / 5 + 3;
			Assert::AreEqual (101, f6.getNumer ());
			Assert::AreEqual (30, f6.getDenom ());			
		}
	};
}
