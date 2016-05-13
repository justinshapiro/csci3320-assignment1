PA1 Writeup

————————————


A. 
I believe that I have completed all aspects of this assignment. I have both Java and a C++ versions, and my C++ version does the specified actions when it is in debug mode. Both versions I have coded to make as efficient as I can make them, and they are both well under 100 lines. I have also included an .xlsx file containing the runtime performance of both programs for one hundred, one million, and one billion hashes. I was not able to obtain a performance time for the 1 billion hashes by the C++ program, as it appeared to be taking way too long (more about this in B). 




B.
 See the .xlsx file also submitted for the exact time in milliseconds that each program took to run for three different number of hashes. I chose to test both programs by running both of them with n = 100, n = 1,000,000 and n = 1,000,000,000. Both programs were tested on my Dell Optiplex 990 machine with 8GB RAM and an Intel Core i5-2400 CPU @ 3.10 GHz.  

In PA1_MD5_2016Sp.pdf, the C++ debug mode was also specified as its own program to test. However, this did not make much sense to me, as the instructions clearly specified that “In mode “A” (debugging mode), your program will read in a single line of input, compute its hash, and then output the computed hash”. Therefore, running the debug build is only valid for n = 1, and cannot be used for values of n > 1. So I included the time that the program took to run one hash, which was about 30 milliseconds.

Based on the performance of the two programs for the three values of n, it appears that Java is much faster than C++ for completing the tasks specified by the assignment. Although the C++ version was slightly faster for n = 100 (20 milliseconds for C++ vs 140 milliseconds for Java), as the value of n increased, the performance of the Java program increased significantly while the performance of the C++ program deteriorated rapidly. For n = 1,000,000, the Java version was almost 30% faster than the C++ version, and for n = 1,000,000,000, the Java version finished in a little less than three hours while the C++ program appeared to be taking well over a day. I could not obtain amount of the time the C++ program took to compute n = 1,000,000,000 because it was taking way too long. After over a day of waiting for the C++ program to finish at n = 1,000,000,000, it was not worth it to keep it going longer. It was clear that the Java program was much better at handling large values. 

I did not expect the C++ program to run so much slower for larger values of n, and I did not expect the runtime of the Java program to be so much more different than the C++ version. The reasons for why the Java version was so much faster than the C++ version are probably beyond the scope of what I currently know about Java, but I can guess that the java.security.MessageDigest class is more efficient than the provided C++ MD5 class. I also noticed the MessageDigest class took in a String, while the MD5 class took in an unsigned char. Therefore, the Java version did not have the requirement of converting a string to a char as the C++ version did. The conversion between data types may have been the reason the C++ program could not keep up.


C.
After completing this assignment, I can conclude that Java is much, much easier to use than C++. This was my first time actually comparing Java and C++ side-by-side, and I am very surprised at the difference. C++ by comparison to Java is much more complex and tedious to complete simple tasks.

What made Java stand out to me is the simplicity of concatenating a string. To concatenate the value of n to the end of “TEST” in Java, all that was needed was the assignment operator in between the “TEST” string and Integer.toString(n). In C++, the more sloppy sprintf function was required, along with creating new variables to the resultant string and value of n for each instance of n.  

The place where I do see C++ and Java about even is in the area of buffers. To output the resultant string as hex values, I chose the method of modifying the string via buffers, rather than writing an algorithm that performs mathematical dec-to-hex calculations on each array element. In C++, stringstream saved the output string to a variable, converting the string to hex via the std::hex method, while Java used the StringBuilder class along with the String.format method to modify a string buffer. Both implementations required around 2 lines of code. I cannot say, however, whether C++’s stringstream/std::hex method is more/less efficient than Java’s StringBuilder/String.format method. 

After completing this assignment, I really want to start using Java more. C++ makes me reinvent the wheel to complete basic tasks such as string concatenation, while in Java these tasks are basically predefined in the syntax of the language. Right now I see Java as a faster language which is much easier to use, even though the syntax may be wordier than C. I am interested in learning more about Java’s limitations, as well as more of its advantages over the classic C languages.
