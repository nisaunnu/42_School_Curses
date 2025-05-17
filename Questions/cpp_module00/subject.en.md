### Assignment name  : cpp_module00

### Expected files   : Warlock.cpp Warlock.hpp
--------------------------------------------------------------------------------
<br>

Make a Warlock class. It has to be in Coplien's form.
<br></br>

It has the following private attributes :
* name (string)
* title (string)
<br></br>

Since they're private, you will write the following getters :
* getName, returns a reference to constant string
* getTitle, returns a reference to constant string
<br></br>

Both these functions will have to be callable on a constant Warlock.
<br></br>

Create the following setter:
* setTitle, returns void and takes a reference to constant string
<br></br>

Your Warlock will also have, in addition to whatever's required by Coplien's
form, a constructor that takes, in this order, its name and title. Your Warlock
will not be able to be copied, instantiated by copy, or instantiated without a
name and a title.
<br></br>

For example :
```cpp
Warlock bob;                            //Does not compile
Warlock bob("Bob", "the magnificent");  //Compiles
Warlock jim("Jim", "the nauseating");   //Compiles
bob = jim;                              //Does not compile
Warlock jack(jim);                      //Does not compile
```
<br>

Upon creation, the Warlock says :

`<NAME>: This looks like another boring day.`
<br></br>

Of course, whenever we use placeholders like `<NAME>`, `<TITLE>`, etc...
in outputs, you will replace them by the appropriate value. Without the < and >.
<br></br>

When he dies, he says:

`<NAME>: My job here is done!`
<br></br>

Our Warlock must also be able to introduce himself, while boasting with all its
might.
<br></br>

So you will write the following function:
* void introduce() const;
<br></br>

It must display:

`<NAME>: I am <NAME>, <TITLE>!`
<br></br>

Here's an example of a test main function and its associated output:
```cpp
int main()
{
  Warlock const richard("Richard", "Mistress of Magma");
  richard.introduce();
  std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

  Warlock* jack = new Warlock("Jack", "the Long");
  jack->introduce();
  jack->setTitle("the Mighty");
  jack->introduce();

  delete jack;

  return (0);
}
```

```bash
~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, Mistress of Magma!$
Richard - Mistress of Magma$
Jack: This looks like another boring day.$
Jack: I am Jack, the Long!$
Jack: I am Jack, the Mighty!$
Jack: My job here is done!$
Richard: My job here is done!$
~$
```
