#!/usr/bin/perl
print "Content-type:text/html\n\n";

=pod
File: quizgrade.cgi
Date: Nov 30, 2019
Author: Adam Abad
=cut

require "./cgi.lib" or &errorpage;
print "<!--File: quizgrade.cgi\nDate: Nov. 30, 2019\nAuthor: Adam Abad\nPurpose: To use a quiz grading cgi program to grade the quiz\n-->\n\n";

$hashRef = &datastring;
%dataHash = %$hashRef;
$quizLoc = "./quiz5.txt";
$quizOutput = "./quiz5.out";

open(quizData, "<$quizLoc") || &errorPage;
open(quizOut, ">>$quizOutput") || &errorPage;

$head = <quizData>;
print quizOut "-------------------------\nResults for " . $dataHash{"username"}. "\n";
print quizOut localtime() . "\n\n";
print &head($head);
print "\t<h1>Results of $head</h1>\n";
print "\tDear ".$dataHash{"username"}.",<br /><br />\n";

$finaloutput = "";
$block = "";
$questCorrect = 0;
$qNum = 0;
@correct = [];
while(my $row = <quizData>) #while loop iterate through rows
{
	chomp $row;
	if(substr($row,0,1)	=~ /[0-9]/ ) #First char is a number (new question)
	{	
		if($qNum != 0) #Check Previous Question
		{
			$finaloutput = $finaloutput . "<br />\t" . &check($qNum) . $block;
		}
		$qNum = $qNum + 1;
		$substr = 0;
		while(!(substr($row,$substr,1) =~ /[A-Za-z]/))
		{
			$substr = $substr + 1;
		}
		$block = substr($row, $substr) . "<br />\n";
	}
	elsif(substr($row,0,1) eq "*")
	{
		push (@correct, substr($row, 1,1)); #Adds correct to the correct array
		$block = $block . "\t\t" . substr($row, 1) . "<br />\n";	
	}
	else
	{
		$block = $block . "\t\t" . $row . "<br />\n";
	}
}

$finaloutput = $finaloutput . &check($qNum) . $block; #Handles last question

print "\tScore: " . $questCorrect . "/" . $qNum . "<br /><br />\n";
print quizOut "Score: " . $questCorrect . "/" . $qNum . "\n";
print $finaloutput;
print &foot;
print quizOut "-------------------------\n\n";
close(quizOut);
close(quizData);

sub check {
	my $num = @_[0];
	$result = "";
	($anw1, $anw2) = split(/;/, $dataHash{"question" . $num});
	$result = $num . ". Your answer was <b>". $anw1 . $anw2 ."</b> and is ";
	if(lc $anw1 eq lc $correct[$num] || lc $anw2 eq lc $correct[$num])
	{
		$result = $result . "<b>correct:</b><br />\n\t";
		$questCorrect = $questCorrect + 1;
		print quizOut $num . ". Answer " . lc $correct[$num] . " is correct.\n"
	}
	else 
	{
		$result = $result . "<b>incorrect. The correct answer is " . $correct[$num] . ":</b><br />\n\t";
		print quizOut $num. ". Answer " . $anw1 . $anw2 . " was incorrect.\n";
		print quizOut "Correct answer is " . lc $correct[$num] . "\n";
	}
	return $result;
}
