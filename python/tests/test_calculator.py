
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
    calc = Calculator("Test")
    arr = [1,2,3,4]
    iter_ = iter(arr)
    assert calc.add_iter(iter_) == sum(arr)

