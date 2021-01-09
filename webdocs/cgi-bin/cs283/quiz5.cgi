#!/usr/bin/perl
print "Content-type:text/html\n\n";

=pod
File: quiz5.cgi
Date: Nov 30, 2019
Author: Adam Abad
=cut

require "./cgi.lib" or &errorpage;
print "<!--File: quiz5.cgi\nDate: Nov. 30, 2019\nAuthor: Adam Abad\nPurpose: To use a quiz grading cgi program to grade the quiz\n-->\n\n";

$hashRef = &datastring;
%dataHash = %$hashRef;
$quizLoc = "./quiz5.txt";

open(quizData, "<$quizLoc") || &errorPage;

$head = <quizData>;
$qNum = 0;
@correct = [];
print &head($head);
print "\t<h1>$head</h1>\n";
print "\tTaking quiz as: ".$dataHash{"username"}."<br /><br />\n";
print "\t<form action='./quizgrade.cgi' method='post' name='quiz'>\n";
print "\t\t" . &hidden("username",$dataHash{"username"}) . "\n";
while(my $row = <quizData>) #while loop iterate through rows
{ 
	chomp $row;
	if(substr($row,0,1) eq '*') #Is the correct response
	{ 
		push (@correct, substr($row, 1,1)); #Adds correct to the correct array
		$output = substr($row,1); #Sets output to remove the '*'
	}
	else 
	{
		$output = $row; #Sets output to the row
	}
	if(substr($row,0,1)	=~ /[0-9]/ ) #First char is a number (new question)
	{	
		$qNum = $qNum + 1; #Add 1 to question for radio values
		print "\t" . &hidden("question" . $qNum,"") . "\n";
		print "\t" . $row . "<br />\n";
	}
	else #Is a response
	{
		$output = radio("question".$qNum,lc substr($output,0,1)) . "\t\t\t" . $output . "<br />\n";
		print "\t\t" . $output;
	}
}
print "\t" . &submit . "\n";
print "\t</table>\n";
print &foot;