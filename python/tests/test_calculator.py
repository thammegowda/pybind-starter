
from mymod import Calculator

def test_add_basic():
    calc = Calculator("Test")
    assert calc.add(2, 3) == 5
    assert calc.add(-1, 1) == 0
    assert calc.add(-1, 2) == 1
    assert calc.add(-2, 1) == -1
    assert calc.add(0, 0) == 0


def test_add_list():
    calc = Calculator("Test")
    arr = [1,2,3,4]
    assert calc.add(arr) == sum(arr)
    

def test_add_iter():
    # send an iterator from python to c++
    calc = Calculator("Test")
    arr = [1,2,3,4]
    iter_ = iter(arr)
    assert calc.add_iter(iter_) == sum(arr)


def test_fibonacci():
    # reads an iterator from cpp
    calc = Calculator("Test")
    fib = calc.fibonacci(10)
    expected = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
    assert list(fib) == expected
