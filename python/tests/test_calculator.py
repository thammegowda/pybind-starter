
from mymod import Calculator

def test_add():
    calc = Calculator("Test")
    assert calc.add(2, 3) == 5
    assert calc.add(-1, 1) == 0
    assert calc.add(-1, 2) == 1
    assert calc.add(-2, 1) == -1
    assert calc.add(0, 0) == 0
    
    
