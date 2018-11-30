#include<stdio.h>
#include<string.h>
#define CHAIR_SIZE 10
#define INPUT_MAX_SIZE 1000

int ChairPair[CHAIR_SIZE][2]={{0,0},{3,2},{1,4},{5,1},{2,6},{7,3},{4,8},{9,5},{6,9},{8,7}};
char ChairStatus[CHAIR_SIZE];


int setStatus(int chair_num, char input_char){
  //printf("%c %c\n",ChairStatus[ChairPair[chair_num][0]], ChairStatus[ChairPair[chair_num][\
1]]);
  ChairStatus[chair_num]=input_char;
  return 0;
}

int check(char Input){
  int chair_num;

  if(Input>='a' && Input<='z'){
    for( chair_num=1; chair_num<CHAIR_SIZE; chair_num++){
      if( ChairStatus[chair_num]==(Input-32)){
        setStatus( chair_num, '-');
        return 0;
      }
    }
  }

  if(Input>='A' && Input<='M'){
    for( chair_num=1; chair_num<CHAIR_SIZE; chair_num++){
      if( ChairStatus[chair_num]=='-' && ChairStatus[ChairPair[chair_num][0]]=='-' && ChairS\
tatus[ChairPair[chair_num][1]]=='-'){
        setStatus( chair_num, Input);
        return 0;
      }
    }
    for( chair_num=1; chair_num<CHAIR_SIZE; chair_num++){
      if( ChairStatus[chair_num]=='-' && ( ChairStatus[ChairPair[chair_num][0]]=='-' || Chai\
rStatus[ChairPair[chair_num][1]]=='-')){
        setStatus( chair_num, Input);
        return 0;
      }
    }
    for( chair_num=1; chair_num<CHAIR_SIZE; chair_num++){
      if( ChairStatus[chair_num]=='-'){
        setStatus( chair_num, Input);
        return 0;
      }
    }
  }
  if(Input>='N' && Input<='Z'){
    for( chair_num=CHAIR_SIZE-1; chair_num>0; chair_num--){
      if( ChairStatus[chair_num]=='-' && ChairStatus[ChairPair[chair_num][0]]=='-' && ChairS\
tatus[ChairPair[chair_num][1]]=='-'){
        setStatus( chair_num, Input);
        return 0;
      }
    }
    for( chair_num=CHAIR_SIZE-1; chair_num>0; chair_num--){
      if( ChairStatus[chair_num]=='-' && ( ChairStatus[ChairPair[chair_num][0]]=='-' || Chai\
rStatus[ChairPair[chair_num][1]]=='-')){
        setStatus( chair_num, Input);
        return 0;
      }
    }
    for( chair_num=CHAIR_SIZE-1; chair_num>0; chair_num--){
      if( ChairStatus[chair_num]=='-'){
        setStatus( chair_num, Input);
        return 0;
      }
    }
  }

  printf("Input error\n");
  return -1;
}

int PrintChair(){
  int chair_num=1;
  do{
    printf("%d", chair_num);
    chair_num=ChairPair[chair_num][0];
  }while( chair_num!=1);
  printf("\n");

  chair_num=1;
  do{
    printf("%c", ChairStatus[chair_num]);
    chair_num=ChairPair[chair_num][0];
  }while( chair_num!=1);
  printf("\n");
}

int main(){
  char Input[INPUT_MAX_SIZE]="NABETanI";

  scanf("%s", Input);
  int InputLength=strlen(Input);
  printf("InputLength=%d\n", InputLength);
  int input_num, chair_num;

  for( chair_num=1; chair_num<CHAIR_SIZE; chair_num++){
    ChairStatus[chair_num]='-';
    //printf("[%d]=%d, %d\n", i, ChairPair[i][0], ChairPair[i][1]);
    //printf("%c", ChairStatus[chair_num]);
  }

  PrintChair();

  for( input_num=0; input_num<InputLength; input_num++){
    check(Input[input_num]);
    PrintChair();

  }

}
