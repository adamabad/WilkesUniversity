<!DOCTYPE html>
<!--
Name: Adam Abad
File: lab3.php
Date: 1/31/2020
-->

<html>
    <head>
        <title>Lab3: People</title>
        <?php
            $emails = array("NIXON.MOSES@WILKES.EDU", "BURNETT.HURLEY@WILKES.EDU", "KRISTI.MELTON@WILKES.EDU", "RICHARD.BRUCE@WILKES.EDU", "PETTY.OWEN8@WILKES.EDU", 
                "DELACRUZ.WEBER1@WILKES.EDU", "NAVARRO.MORROW@WILKES.EDU", "JENNA.WOODS@WILKES.EDU", "KATHERYN.HARVEY@WILKES.EDU", "DONNA.WOOD@WILKES.EDU", 
                "SCHNEIDER.WADE@WILKES.EDU", "FAYE.TANNER@WILKES.EDU", "LYNNETTE.CONLEY@WILKES.EDU", "BURTON.WILKINS@WILKES.EDU", "DELEON.MCCULLOUGH@WILKES.EDU", 
                "HURST.KELLEY@WILKES.EDU", "BARRETT.NIXON@WILKES.EDU", "ANTHONY.CANTU@WILKES.EDU", "KELSEY.MAY7@WILKES.EDU", "ALYSSA.PECK@WILKES.EDU", 
                "RICE.COPELAND@WILKES.EDU", "INGRID.POLLARD@WILKES.EDU", "DUDLEY.BENSON@WILKES.EDU", "BOOTH.HENSLEY2@WILKES.EDU", "ELVA.BROWN@WILKES.EDU", 
                "BRANDI.STANTON@WILKES.EDU", "OSBORN.VELEZ@WILKES.EDU", "KATINA.MURRAY@WILKES.EDU", "MAYS.LOWE@WILKES.EDU", "MIRIAM.TRUJILLO@WILKES.EDU", 
                "GENA.JACOBS@WILKES.EDU", "LAKISHA.HARTMAN@WILKES.EDU", "MAUREEN.PERKINS@WILKES.EDU", "TRISHA.CLARKE@WILKES.EDU", "RANDOLPH.GRAHAM@WILKES.EDU", 
                "ISABEL.WARD@WILKES.EDU", "ANGELA.FARLEY@WILKES.EDU", "KLINE.DOTSON@WILKES.EDU", "ELBA.BARNETT@WILKES.EDU", "BEACH.RATLIFF@WILKES.EDU", 
                "FERNANDEZ.SULLIVAN12@WILKES.EDU", "TONIA.ODONNELL@WILKES.EDU", "EMERSON.IRWIN@WILKES.EDU", "JOCELYN.MCLEAN@WILKES.EDU", "FRANCIS.ROBBINS@WILKES.EDU", 
                "MAVIS.GAINES@WILKES.EDU", "LYNCH.LAWRENCE@WILKES.EDU", "OLGA.SIMPSON@WILKES.EDU", "LAUREL.LYNN@WILKES.EDU", "HODGES.FISHER@WILKES.EDU");
            $emailArray = array();
            foreach($emails as $key => $email) {
                $temp = explode(".",strtolower($email));
                $first = ucfirst($temp[0]);
                $last = ucfirst(explode("@",str_replace(array("0","1","2","3","4","5","6","7","8","9"),"",$temp[1]))[0]);
                $username = explode("@",$email)[0];
                $emailArray[$key] = array("first" => $first,"last" =>$last,
                                "username" => strtolower($username));
                $firstname[$key] = $emailArray[$key]["first"];
                $lastname[$key] = $emailArray[$key]["last"];
            }
            array_multisort($lastname,$firstname,$emailArray);
        ?>
    </head>
    <body>
        <table>
            <thead>
                <th>First</th>
                <th>Last</th>
                <th>Username</th>
            </thead>
            <?php
                foreach($emailArray as $ID) {
                    echo "<tr>\n<td>".$ID["first"]."</td>\n<td>".$ID["last"]."</td>\n<td>".$ID["username"]."</td>\n</tr>\n";
                }
            ?>
        </table>
    </body>
</html>