#!/usr/bin/perl
print "Content-type:text/html\n\n";

=pod
File: quiz3.cgi
Date: Nov 12, 2019
Author: Adam Abad
=cut

require "./cgi.lib";
print "<!--File: quiz3.cgi\nDate: Nov. 12, 2019\nAuthor: Adam Abad\nPurpose: Use a cgi.lib on the perl executable\n-->\n\n";

$title = 'PERL Generated Quiz';
print &head($title);
print "<form action='http://www.cknuckles.com/cgi/echo.cgi' method='get' name='quiz'>\n";
print "\t<table border='0'>\n\t\t<tr>\n\t\t\t<td>FirstName:</td>\n";
print "\t\t\t<td>".&textbox('firstname','',20,20)."\t\t\t</td>\n\t\t</tr>\n\t</table>\n";
print "\t<table border='0' cellpadding='5' width='600'>\n";
print "\t\t<tr>\n";
print "\t\t1. The Y2K event occured during which holiday in 2000?<br />\n";
print "\t\t".&hidden("question1","")."\n";

@question1 = ('A. Christmas','B. New Years','C. Valentines Day','D, 4th of July','E. Thanksgiving');
@question2 = ('A. Java','B. JavaScript','C. PERL','D. PYTHON','E. HTTPS');
%question3 = (
	"" => "Choose Year",
	"freshman" => "Freshman",
	"sophmore" => "Sophmore",
	"junior" => "Junior",
	"senior" => "Senior",
);
%question4 = (
	"cs115" => "CS115",
	"cs116" => "CS116",
	"cs225" => "CS225",
	"cs226" => "CS226",
	"cs246" => "CS246",
);

@letters = ('a','b','c','d','e');

for (my $i=0; $i < 5; $i++) 
{
	print "\t\t".radio("question1",$letters[$i],"")."\t\t\t".$question1[$i]."<br />\n";
}
print "\t\t</tr>\n";
print "\t\t<tr>\n\t\t2. Which of the following is a programming language<br />\n";
print "\t\t".&hidden("question2","")."\n";

for (my $i=0; $i < 5; $i++) 
{
	print "\t\t".checkbox("question2",$letters[$i],"")."\t\t\t".$question2[$i]."<br />\n";
}
print "\t\t</tr>\n";
print "\t\t<tr>\t\t3. I am currently in my ______ year at Wilkes.<br />\n";
print "\t\t".&hidden("question3","")."\n";
print &menu("question3",\%question3,"Choose Year")."<br />\n";
print "\t\t</tr>\n";

print "\t\t<tr>\n\t\t4. I have taken the following classes so far at Wilkes.<br />\n";
print "\t\t".&hidden("question4","")."\n";
print &multiple("question4",\%question4,5)."<br />\n";
print "\t\t</tr>\n";
print "\t\t".&submit;
print "\t</table>\n";

print "</form>\n";
print &foot;
