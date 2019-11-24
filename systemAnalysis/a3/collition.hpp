#ifndef COLLITION
#define COLLITION

enum collition {
  NoCollition,
  IdCollition,
  DataCollition,
  NoDetection,
};

char collitionToChar(collition c) {
  auto col = '?';

  switch (c) {
    case NoCollition:
      break;

    case IdCollition:
      break;

    case DataCollition:
      break;

    case NoDetection:
      break;

    default:
      col = '!';
      break;
  }
  return col;
}

#endif
