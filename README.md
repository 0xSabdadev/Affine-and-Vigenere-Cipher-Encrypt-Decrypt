# Affine-and-Vigenere-Cipher-Encrypt-Decrypt

<h2> 1.) Affine Cipher </h2>
<h3><u>Encryption</h3>

It uses modular arithmetic to transform the integer that each plaintext letter corresponds to into another integer that correspond to a ciphertext letter. 
The encryption function for a single letter is :

                           E ( x ) = ( a x + b ) mod m
 
                           modulus m: size of the alphabet
                           a and b: key of the cipher.
                           a must be chosen such that a and m are coprime.

<h3><u>Decryption</h3>

                           D ( x ) = a^-1 ( x - b ) mod m </h4>

                           a^-1 : modular multiplicative inverse of a modulo m. i.e., it satisfies the equation
                           1 = a a^-1 mod m .

<h2> 2.) Vigenere Cipher </h2>
<h3><u>Encryption</h3>

The plaintext(P) and key(K) are added modulo 26.
                                                        
                            Ei = (Pi + Ki) mod 26 </h4>

<h3><u>Decryption</h3>
  
                            Di = (Ei - Ki + 26) mod 26 </h4>
