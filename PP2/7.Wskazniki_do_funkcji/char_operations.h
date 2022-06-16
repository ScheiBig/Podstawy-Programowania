#pragma once

typedef char (*char_op)(char);

char* letter_modifier(const char* input_text, char_op operation);

char lower_to_upper(char c);
char upper_to_lower(char c);
char space_to_dash(char c); 
char reverse_letter(char c);

/*
For a long time it puzzled me how something so expensive, so leading edge, could be so useless. And then it occurred to me that a computer is a stupid machine with the ability to do incredibly smart things, while computer programmers are smart people with the ability to do incredibly stupid things. They are, in short, a perfect match.  - Bill Bryson The human spirit must prevail over technology.-Albert Einstein  Fine, Java MIGHT be a good example of what a programming language should be like. But Java applications are good examples of what applications SHOULDN T be like.  - pixadel Love is the absence of judgment. - Dalai Lama XIV True happiness is... to enjoy the present, without anxious dependence upon the future. - Lucius Annaeus Seneca At forty, I was too old to work as a programmer myself anymore; writing code is a young person s job. - Michael Crichton  The attention span of a computer is only as long as its power cord.   - Author Unknown Communications tools don t get socially interesting until they get technologically boring.-Clay Shirky The best programs are written so that computing machines can perform them quickly and so that human beings can understand them clearly. A programmer is ideally an essayist who works with traditional aesthetic and literary forms as well as mathematical concepts, to communicate the way that an algorithm works and to convince a reader that the results will be correct. - Donald Ervin Knuth  If GM had kept up with technology like the computer industry has, we would all be driving $25 cars that got 1000 MPG.  - Bill Gates, Founder of Microsoft It s not the load that breaks you down, it s the way you carry it. - Lou Holtz The most technologically efficient machine that man has ever invented is the book.-Northrop Frye Is artificial intelligence less than our intelligence? - Spike Jonze Tell the truth, or someone will tell it for you. - Stephanie Klein  The problem with troubleshooting is that trouble shoots back.   - Author Unknown
*/