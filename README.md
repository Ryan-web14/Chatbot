# C++ Rule-Based Chatbot

A small conversational agent written in C++ from scratch, with no NLP library and no machine learning. Responses are produced by pattern matching over a set of declarative rules.

The goal was to build the full loop myself (input handling, matching, response selection, conversation state) rather than to wrap an existing engine.

## How it works

```
user input
    │
    ▼
normalization        lowercase, strip punctuation, collapse whitespace
    │
    ▼
rule matching        keyword / pattern lookup over the rule set
    │
    ▼
response selection   first match wins; random pick among variants
    │
    ▼
fallback             default reply when no rule matches
```

There is no tokenizer, no parser, no intent classifier. The matching is deliberately simple and the architecture is the point: each stage is isolated so a more serious implementation can replace it without touching the rest.

## Build

```bash
g++ -std=c++17 -O2 -o chatbot src/*.cpp
./chatbot
```

Or with CMake:

```bash
cmake -B build && cmake --build build
./build/chatbot
```

Requires a C++17 compiler. No external dependencies.

## Usage

```
$ ./chatbot
> hello
Hi. What can I do for you?
> quit
```

Type `quit` or `exit` to end the session.

## Adding rules

Rules live in `data/rules.txt`, one per line:

```
keyword(s) | response | alternative response
```

Nothing is recompiled when the file changes. The rule set is read at startup.

## Project layout

```
src/        source files
include/    headers
data/       rule definitions
```

## Limitations

Worth stating plainly, since they are inherent to the approach and not bugs:

- No understanding of word order, negation, or context beyond the current turn
- Synonyms must be listed explicitly in the rules
- Response quality scales linearly with how many rules are written by hand
- A typo defeats the matcher entirely

## Possible extensions

The codebase is structured so each of these can be added independently:

- **Fuzzy matching**: Levenshtein distance on tokens to tolerate typos
- **Conversation state**: carry context across turns instead of treating each input in isolation
- **Weighted rules**: score all matches and pick the best rather than the first
- **Stemming**: reduce words to a common root so fewer rules cover more inputs
- **Intent classification**: replace the matcher with a trained classifier, keeping the same interface
- **Persistence**: log conversations to disk for later analysis

## License

MIT
