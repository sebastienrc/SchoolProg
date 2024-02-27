// StringBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 1DAE12 Rojas Castillo Sebastien

#include "pch.h"
#include <iostream>

int main()
{
    std::string Story{ "Long before time as we count it, there lived in India a great and just King whose name was Vikramaditya. When he died, his beautiful palace and city of marble fell into ruins: and people remembered nothing but his name, and that he was great and good, and wise and gentle.\nOne day, some boys who were minding cows led them near a green mound among the ruins : and while the cows cropped the grass, the boys played.\nAnd one of them invented this game.\n“I shall be the Judge,” he said, “and you shall bring your quarrels to me.I will do justice.”\nSo he sat on the mound;and the boys ran awayand whispered,and made a tale of wrong,and brought it[Pg 11] to the boy on the mound, who did justice.\nBut the odd thing was, that the “justice” was such wisdom, that even through their play, the boys felt that something wonderful had happened to their playfellow.\n“He is a real Judge, not a play Judge,” was what they said.\nAnd they told their parents;and soon all the village got into the habit of coming to the boy on the mound to settle disputes.And everyone was always sure that his judgment was right.\nNow there lived close to the ruined city, a King greatand powerful:and to his ears also came the story of the boy doing justice on the green mound.And the King laughedand said, “Why, he is sitting on the seat of Vikramaditya; that is why he is wise.”\nThen the King began to wish the throne for himself.And he sent men with pickaxesand shovels, who dug away the boy’s green mound.Deeperand deeper they went, till they came to a throne of black marble, resting on the backs of twenty - four beautiful carved eagles of marble.And the throne was taken to the palace of the King,and a great day of rejoicing was proclaimed, when the King would mount the throne.\nOn the great day the King came in state, with his mace bearers,and the men who called his titles,and the men who carried the State jewels,and the men who fanned him with great fans made of the green - blue eyes of a peacock’s tail.\nBut when the King would have mounted the throne, one of the carven eagles which bore the throne on its[Pg 14] back, came aliveand spoke to the Kin" };
    std::cout << "-- Explore String Class" << std::endl;
    std::cout << Story << std::endl;
    std::cout << "size: " << Story.size() << std::endl;
    std::cout << "size: " << Story.length() << std::endl;


    std::cout << Story.c_str() << std::endl;

}

