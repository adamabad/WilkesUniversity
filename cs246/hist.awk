BEGIN{
    numCount[0];
    numSave[0];
}
 {
    check = 0;
    total++;
    for(i in numSave)
	if($1 == numSave[i])
	{ 
	    check = 1;
	    numCount[i]++;
	}
     if (check == 0)
     {
	 len = length(numSave);
         numSave[len] = $1;
         numCount[len] = 1;
    }
}
END{
    for(q = 0; q < length(numSave); q++)
	for(z = 0; z < q; z++)
	    if(numSave[q] < numSave[z])
	    {
		hold = numSave[q];
		holdValue = numCount[q];

		numSave[q] = numSave[z];
		numCount[q] = numCount[z];
		
		numSave[z] = hold;
		numCount[z] = holdValue;
	    }
    
    for(x = 0; x < length(numSave); x++)
	if(numCount[x] != 0)
	{
	    asterNum =(numCount[x] / total) * 50 + 1;
	    printf "%2d: %8d ",numSave[x],numCount[x];
	    for(w = 0; w < int(asterNum); w++)
		printf("%s","*");
	    print "";
	}
}

