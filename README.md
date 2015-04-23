# ProjectGameEngine

Game Engine
=============

Update
=========

GLEW 
----
has been replaced with an internal Extension class that is added directly into the project
this will reduce the need to link an external library to be linked reducing the risk of Linker Errors. 
The internal class was generated using glLoadGen theres a link below if you are interested. further more
the class will enfore OpenGL 4.3 standards Deprecated OpenGL functions will longer be accessable

SFML
----
is statically linked to project further reducing the need for external DLLs









glLoadGen
https://bitbucket.org/alfonse/glloadgen/wiki/Home
