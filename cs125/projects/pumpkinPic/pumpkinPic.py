# File: pumpkinPic.py
# Date: October 17, 2017
# Author: Adam Abad
# Purpose: To make a picture using polygons and graphics

from graphics import *

def main():
    win = GraphWin("Pumpkin Picture",500,500)
    win.setBackground("white")
    
    #color palate from (http://imagecolorpicker.com/)
    darkorange = color_rgb(207,12,5)
    pumpkinorange = color_rgb(251,110,0)
    hatshade = color_rgb(53,53,53)
    buckledark = color_rgb(47,48,47)
    
    #creates text
    messageLine1 = Text(Point(250,380),"Adam Abad")
    messageLine2 = Text(Point(250,400),"likes")
    messageLine3 = Text(Point(250,420),"CS 125")

    #recolors text
    messageLine1.setTextColor(darkorange)
    messageLine2.setTextColor(darkorange)
    messageLine3.setTextColor(darkorange)
    
    #draws text
    messageLine1.draw(win)
    messageLine2.draw(win)
    messageLine3.draw(win)

    #draws pumpkin
    background = Polygon(Point(218,160), Point(221,169), Point(230,180), Point(240,186), 
                        Point(254,192), Point(267,203), Point(279,218), Point(285,228), 
                        Point(289,234), Point(292,235), Point(305,256), Point(324,262), 
                        Point(343,264), Point(357,265), Point(369,265), Point(385,262), 
                        Point(362,276), Point(335,283), Point(324,285), Point(329,296), 
                        Point(329,304), Point(325,310), Point(320,318), Point(315,327), 
                        Point(309,331), Point(305,332), Point(300,331), Point(297,335), 
                        Point(292,339), Point(285,341), Point(280,342), Point(275,341), 
                        Point(272,343), Point(267,345), Point(256,345), Point(251,342), 
                        Point(245,344), Point(236,342), Point(227,340), Point(217,335), 
                        Point(215,334), Point(206,330), Point(200,328), Point(196,324), 
                        Point(189,319), Point(184,313), Point(178,301), Point(178,297), 
                        Point(182,291), Point(176,290), Point(168,290), Point(157,288), 
                        Point(148,285), Point(149,273), Point(137,281), Point(131,277), 
                        Point(123,271), Point(121,264), Point(118,262), Point(118,259), 
                        Point(124,255), Point(133,254), Point(141,254), Point(152,252), 
                        Point(162,252), Point(173,251), Point(183,251), Point(193,251), 
                        Point(204,250), Point(208,253), Point(212,245), Point(217,238), 
                        Point(219,232), Point(221,224), Point(224,218), Point(229,212), 
                        Point(232,207), Point(224,205), Point(219,199), Point(217,191), 
                        Point(214,183), Point(213,172), Point(214,163), Point(217,160))
    background.draw(win)
    background.setFill("Black")
    
    #Draws Hat
    hatShading1 = Polygon(Point(217,168), Point(223,176), Point(227,182), Point(231,183), 
                        Point(224,188), Point(232,187), Point(236,186), Point(237,187), 
                        Point(231,190), Point(238,190), Point(242,191), Point(247,191), 
                        Point(253,194), Point(255,197), Point(248,201), Point(244,206), 
                        Point(245,213), Point(250,217), Point(254,219), Point(259,221), 
                        Point(267,222), Point(273,224), Point(266,226), Point(258,227), 
                        Point(252,227), Point(245,227), Point(283,233), Point(278,234), 
                        Point(270,234), Point(250,235), Point(239,235), Point(227,232), 
                        Point(222,231), Point(221,229), Point(222,223), Point(223,221), 
                        Point(225,217), Point(228,211), Point(234,208), Point(238,202), 
                        Point(240,199), Point(236,199), Point(230,201), Point(226,200), 
                        Point(223,198), Point(220,194), Point(219,190), Point(217,183), 
                        Point(216,176), Point(215,169))
    hatShading1.draw(win)
    hatShading1.setFill(hatshade)
    hatShading2 = Polygon(Point(122,258), Point(147,253), Point(171,252), Point(208,251), 
                        Point(229,256), Point(251,260), Point(282,262), Point(302,258), 
                        Point(318,263), Point(335,266), Point(356,266), Point(375,266), 
                        Point(350,278), Point(328,282), Point(310,285), Point(300,286), 
                        Point(289,268), Point(276,284), Point(253,279), Point(234,277), 
                        Point(210,270), Point(199,267), Point(183,263), Point(164,258), 
                        Point(151,258), Point(135,258), Point(123,260))
    hatShading2.draw(win)
    hatShading2.setFill(hatshade)
    hatShading3 = Polygon(Point(342,274), Point(326,277), Point(325,272), Point(323,269),
                        Point(315,270), Point(301,271), Point(304,268), Point(302,264),
                        Point(292,266), Point(281,266), Point(256,264), Point(301,263),
                        Point(312,266), Point(333,271), Point(342,271))
    hatShading3.draw(win)
    hatShading3.setFill("black")
    hatShading4 = Polygon(Point(233,265), Point(217,263), Point(205,255), Point(163,255), 
                        Point(219,267), Point(195,258))
    hatShading4.draw(win)
    hatShading4.setFill("black")
    buckle1 = Polygon(Point(249,239), Point(247,241), Point(246,258), Point(276,260), 
                        Point(278,258), Point(278,241), Point(274,239), Point(250,239))
    buckle1.draw(win)
    buckle1.setFill("grey")
    buckleInside = Polygon(Point(255,247), Point(270,247), Point(270,254), Point(255,254))
    buckleInside.draw(win)
    buckleInside.setFill("black")
    buckleShading = Polygon(Point(274,260), Point(247,258), Point(251,254), Point(251,241), 
                        Point(271,244), Point(272,245), Point(254,244), Point(256,254), 
                        Point(271,259))
    buckleShading.draw(win)
    buckleShading.setFill(buckledark)
    buckleShading.setOutline(buckledark)
    
    #pumpkin draw
    pumpkin = Polygon(Point(287,275), Point(295,283), Point(289,285), Point(284,290), 
                        Point(307,293), Point(305,289), Point(321,287), Point(324,296), 
                        Point(323,308), Point(319,317), Point(314,325), Point(308,329), 
                        Point(298,330), Point(294,335), Point(287,338), Point(283,338), 
                        Point(278,338), Point(271,340), Point(263,343), Point(256,343), 
                        Point(249,340), Point(241,340), Point(231,339), Point(227,338), 
                        Point(220,333), Point(213,332), Point(201,325), Point(196,322), 
                        Point(185,311), Point(181,301), Point(181,297), Point(182,292), 
                        Point(184,288), Point(190,281), Point(197,277), Point(202,273), 
                        Point(279,288))
    pumpkin.draw(win)
    pumpkin.setFill(pumpkinorange)
    eye1 = Polygon(Point(243,289), Point(238,281), Point(229,280), Point(222,282), 
                        Point(215,287), Point(215,290))
    eye1.draw(win)
    eye1.setFill("black")
    eye1Shading = Polygon(Point(247,292), Point(214,290), Point(216,288), Point(240,289), 
                        Point(239,285), Point(235,281), Point(230,280), Point(241,283), 
                        Point(243,285), Point(247,292))
    eye1Shading.draw(win)
    eye1Shading.setFill(darkorange)
    eye1Shading.setOutline(darkorange)
    eye2Shading = Polygon(Point(283,292), Point(308,294), Point(307,289), Point(304,289), 
                        Point(304,292))
    eye2Shading.draw(win)
    eye2Shading.setFill(darkorange)
    eye2Shading.setOutline(darkorange)

    nose = Polygon(Point(265,289), Point(272,302), Point(256,304))
    nose.draw(win)
    nose.setFill("black")
    noseShading = Polygon(Point(265,289), Point(278,305), Point(254,305), Point(257,303), 
                        Point(270,300))
    noseShading.draw(win)
    noseShading.setFill(darkorange)
    noseShading.setOutline(darkorange)
    mouth = Polygon(Point(229,325), Point(224,322), Point(217,315), Point(213,304), 
                        Point(220,311), Point(220,313), Point(228,316), Point(229,313), 
                        Point(271,319), Point(273,323), Point(283,324), Point(283,319), 
                        Point(302,310), Point(296,321), Point(293,319), Point(288,322), 
                        Point(290,326), Point(277,331), Point(270,331), Point(261,331), 
                        Point(253,329), Point(246,327), Point(241,327), Point(239,321), 
                        Point(231,320), Point(231,325))
    mouth.draw(win)
    mouth.setFill("black")
    toothBottomShading = Polygon(Point(227,325), Point(230,318), Point(239,321), Point(240,321), 
                        Point(232,321), Point(231,325))
    toothBottomShading.draw(win)
    toothBottomShading.setFill(darkorange)
    toothBottomShading.setOutline(darkorange)
    mouthBottomShading = Polygon(Point(241,325), Point(239,327), Point(245,329), Point(255,331), 
                        Point(265,332), Point(275,331), Point(284,330), Point(291,325), 
                        Point(289,322), Point(293,320), Point(290,317), Point(286,319), 
                        Point(286,323), Point(276,327), Point(264,326), Point(255,327), 
                        Point(247,325), Point(240,323))
    mouthBottomShading.draw(win)
    mouthBottomShading.setFill(darkorange)
    mouthBottomShading.setOutline(darkorange)
    mouthRightShading = Polygon(Point(297,311), Point(303,308), Point(301,316), Point(294,322), 
                        Point(294,318), Point(298,315))
    mouthRightShading.draw(win)
    mouthRightShading.setFill(darkorange)
    mouthRightShading.setOutline(darkorange)
    upperTooth1Shading = Polygon(Point(273,319), Point(275,323), Point(271,322), Point(269,319))
    upperTooth1Shading.draw(win)
    upperTooth1Shading.setFill(darkorange)
    upperTooth1Shading.setOutline(darkorange)
    upperTooth2Shading = Polygon(Point(218,309), Point(219,313), Point(221,315), Point(221,310))
    upperTooth2Shading.draw(win)
    upperTooth2Shading.setFill(darkorange)
    upperTooth2Shading.setOutline(darkorange)

    pumpkinShading1 = Polygon(Point(315,290), Point(319,287), Point(320,305), Point(315,315), 
                        Point(306,326), Point(300,328), Point(312,314), Point(315,301), 
                        Point(315,297), Point(313,290))
    pumpkinShading1.draw(win)
    pumpkinShading1.setFill(darkorange)
    pumpkinShading1.setOutline(darkorange)
    pumpkinShading2 = Polygon(Point(219,276), Point(208,284), Point(205,290), Point(204,296), 
                        Point(203,301), Point(205,311), Point(206,314), Point(209,321), 
                        Point(212,325), Point(213,329), Point(208,324), Point(205,319), 
                        Point(203,315), Point(200,310), Point(198,302), Point(200,294), 
                        Point(200,289), Point(207,282))
    pumpkinShading2.draw(win)
    pumpkinShading2.setFill(darkorange)
    pumpkinShading2.setOutline(darkorange)
    pumpkinShading3 = Polygon(Point(201,274), Point(188,281), Point(181,297), Point(184,310), 
                        Point(200,324), Point(192,315), Point(187,305), Point(187,296), 
                        Point(190,287), Point(197,278))
    pumpkinShading3.draw(win)
    pumpkinShading3.setFill(darkorange)
    pumpkinShading3.setOutline(darkorange)

    win.getMouse()
    win.close()
    
main()
