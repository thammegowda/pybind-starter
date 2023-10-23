import logging

log = logging.getLogger(__name__)
log.setLevel(level=logging.INFO)
try:
    import _mymod
except:
    logging.error("Unable to import native lib _mymod")
    raise


class Calculator(_mymod.Calculator):
    """Python wrapper for C++ Calculator class"""
    pass        # nothing to override
