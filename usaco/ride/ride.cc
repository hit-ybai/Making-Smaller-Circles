/*
ID: baiyu033
PROG: ride
LANG: C++11
*/

/*
 * Your Ride Is Here
 *
 * The group "USACO" would be 21 * 19 * 1 * 3 * 15 = 17955.
 * If the group's number mod 47 is the same as the comet's number mod 47,
 * then you need to tell the group to get ready!
 *
 * Write a program which reads in the name of the comet and the name of the group
 * and figures out whether according to the above scheme the names are a match,
 * printing "GO" if they match and "STAY" if not.
 *
 * The names of the groups and the comets will be a string of capital letters
 * with no spaces or punctuation, up to 6 characters long.
 *
 * Examples:
 * Input   Output
 * COMETQ
 * HVNGAT   GO
 * ABSTAR
 * USACO    STAY
 *
 * INPUT FORMAT
 * Line 1:
 *   An upper case character string of length 1..6 that is the name of the comet.
 * Line 2:
 *   An upper case character string of length 1..6 that is the name of the group.
 *
 * SAMPLE INPUT (file ride.in)
 * COMETQ
 * HVNGAT
 *
 * OUTPUT FORMAT
 * A single line containing either the word "GO" or the word "STAY".
 *
 * SAMPLE OUTPUT (file ride.out)
 * GO
 *
 * OUTPUT EXPLANATION
 * Converting the letters to numbers:
 * C   O   M   E   T   Q   
 * 3   15  13  5   20  17  
 * H   V   N   G   A   T
 * 8   22  14  7   1   20  
 * Then calculate the product mod 47:
 * 3 * 15 * 13 * 5 * 20 * 17 = 994500 mod 47 = 27
 * 8 * 22 * 14 * 7 *  1 * 20 = 344960 mod 47 = 27
 * Because both products evaluate to 27 (when modded by 47), the mission is 'GO'. 
 */

#include <cstdio>
#include <cctype>

int
hash(int value)
{
  const int ModNum = 47;
  return value % ModNum;
}

int
char_to_score(char alphabet)
{
  const int BaseNum = 'A' - 1;
  return toupper(alphabet) - BaseNum;
}

int
name_to_score(char *name_buffer)
{
  int score = 1;
  for (int i = 0; name_buffer[i] != '\n'; ++i)
  {
    printf( "%d\n", char_to_score(name_buffer[i]) );
    score = hash( score * char_to_score(name_buffer[i]) );
  }
  return score;
}

int
main()
{
  const int MaxNameLength = 8; // Max Length String: "******\n\0"

  FILE *fin = fopen("ride.in", "r");
  char comet[MaxNameLength], group[MaxNameLength];

  fgets(comet, sizeof(comet), (FILE*) fin);
  fgets(group, sizeof(group), (FILE*) fin);

  fclose(fin);

  FILE *fout = fopen("ride.out", "w");
  if ( name_to_score(comet) == name_to_score(group) )
    fprintf(fout, "GO\n");
  else
    fprintf(fout, "STAY\n");
  fclose(fout);

  return 0;
}

