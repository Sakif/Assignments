using Unity.Burst;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Events;

public class TypingGame : MonoBehaviour {
  public List<word> words;
  public Text display;

  [BurstCompile]
  void Update() {
    string input = Input.inputString;
    if (input.Equals("")) {
      return;
    }

    char char_input = input[0];
    string typeing = "";

    foreach (var word in words) {
      if (word.continue_text(char_input)) {
        string typed = word.get_typed();
        typeing += typed + "\n";
        if (typed.Equals(word.text)) {
          Debug.Log("Typed: " + word.text);
          words.Remove(word);
          break;
        }
      }
    }
    display.text = typeing;
  }
}

[System.Serializable]
public class word {
  public string text;
  public UnityEvent on_typed;
  string has_typed = "";
  int current_character = 0;

  public word(string t) {
    text = t.ToLower();
    has_typed = "";
    current_character = 0;
  }

  public bool continue_text(char c) {
    if (c.Equals(text[current_character])) {
      current_character++;
      has_typed = text.Substring(0, current_character);

      if (current_character >= text.Length) {
        on_typed.Invoke();
        current_character = 0;
      }
      return true;
    } else {
      current_character = 0;
      has_typed = "";
      return false;
    }
  }

  public string get_typed() {
    return has_typed;
  }
}