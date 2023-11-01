#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.4 rec/Lab 6.4 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            int n = 10;
            int* a = new int[n];
            int Low = -11;
            int High = 13;
            generateArray(a, n, Low, High, 0);
            Assert::AreEqual(0, Sum(a, n, 0 ,0), 0.0001);
        }
    };
}