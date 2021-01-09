#!/usr/bin/perl
print "Content-type:text/html\n\n";

=pod
File: login4.cgi
Date: Nov 18, 2019
Author: Adam Abad
=cut

require "./cgi.lib";

print "<!--File: login4.cgi\nDate: Nov. 18, 2019\nAuthor: Adam Abad\nPurpose: Pass data to quiz4.cgi using POST and to have it decoded using cgi.lib\n-->\n\n";

$username = 'username';
$passwordname = 'pass';
$title = 'Login Page';

print &head($title);
print "\t<form action='quiz4.cgi' method='get' name='loginform'>\n\t\t<table>\n\t\t<tr>\n";
print "\t\t\t<td>Username:</td>\n";

print "\t\t\t<td>".&textbox($username,'',20,20)."\t\t\t</td>\n\t\t</tr>\n";
print "\t\t<tr>\n\t\t\t<td>Password:</td>\n\t\t\t<td>".&password($passwordname,'',20,20)."\t\t\t</td>\n\t\t</tr>\n";
print "\t\t<tr>\n\t\t\t<td>\n\t\t\t\t".&submit."\t\t\t</td>\n\t\t</tr>\n\t\t</table>";
print &foot;
