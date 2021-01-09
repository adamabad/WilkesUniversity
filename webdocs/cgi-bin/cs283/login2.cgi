#!/usr/bin/perl
print "Content-type:text/html\n\n";

print <<PAGE ;
<html>
    <!--
    Name: Adam Abad
    File: login2.cgi
    Date: Oct. 30, 2019
    Purpose: To use a PERL cgi program to display the login page.
    -->
  <head>
    <title>Login Form</title>
  </head>
  <body>
    <form action="quiz2.cgi" method="get" name="loginform">
      <table>
	<tr>
	  <td>Username:</td>
	  <td><input type="text" name="username" /></td>
	</tr>
	<tr>
	  <td>Password:</td>
	  <td><input type="password" name="pass" /></td>
	</tr>
	<tr>
	  <td><input type="submit" /></td>
	</tr>
	<script language="JavaScript">
	  <!--
	  document.loginform.onsubmit=validate;

	  function validate() 
	  {
	    var uName = document.loginform.username.value;
	    if(uName.length < 4 || uName.length > 8)
	    {  
	      alert("Username must be between 4 and 8 characters.");
	      document.loginform.username.focus();
	      document.loginform.username.select();
	      return false;
	    }
	    var validUName = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	    for(var x = 0; x < uName.length; x++)
	    {
	      if(validUName.indexOf(uName.charAt(x)) == -1)
	      {
	        alert("Username can only contain alphanumeric characters. (a-z, A-Z, 0-9)");
		document.loginform.username.focus();
		document.loginform.username.select();
		return false;
	      }
	    }
	    if(!isNaN(uName.charAt(0))) 
	    {
	      alert("Username must begin with an alphabetic character.");
	      document.loginform.username.focus();
	      document.loginform.username.select();
	      return false;
	    }
	    var pWord = document.loginform.pass.value;
	    if(pWord.length < 4 || pWord.length > 8)
	    {
	      alert("Password must be between 4 and 8 characters.");
	      document.loginform.pass.focus();
	      document.loginform.pass.select();
	      return false;
	    }
	    var validPword = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_";
	    for(var z = 0; z < pWord.length; z++)
	    {
	      if(validPword.indexOf(pWord.charAt(z)) == -1)
	      {
	        alert("Password can only contain alphanumeric characters, underscores, and hyphens. (a-z, A-Z, 0-9, -, _)");
		document.loginform.pass.focus();
		document.loginform.pass.select();
		return false;
	      }
	    }
	    if(pWord.charAt(0) == "-" || pWord.charAt(0) == "_" || !isNaN(pWord.charAt(0)))
	    {
	      alert("Password must begin with an alphabetic character.");
	      document.loginform.pass.focus();
	      document.loginform.pass.select();
	      return false;
	    }
	    return true;
	  }
	    -->
	</script>
    </form>
  </body>
</html>
PAGE
