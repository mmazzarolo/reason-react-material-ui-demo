[%bs.raw {|require('./app.css')|}];

type state = {
  name: string,
  players: int,
  platform: string,
  release: int,
  genre: string,
  websiteUrl: string,
  wikiUrl: string,
  youtubeUrl: string,
  steamUrl: string,
  notes: string,
  author: string
};

type action =
  | ChangeName(string)
  | ChangePlayers(int)
  | ChangePlatform(string)
  | ChangeGenre(string)
  | ChangeWebsiteUrl(string)
  | ChangeWikiUrl(string)
  | ChangeYoutubeUrl(string)
  | ChangeSteamUrl(string)
  | ChangeNotes(string)
  | ChangeAuthor(string);

type platform = {
  value: string,
  label: string
};

let platforms: list(platform) = [
  {value: "steam", label: "Steam"},
  {value: "wii", label: "Nintendo Wii"},
  {value: "wiiu", label: "Nintendo Wii U"},
  {value: "ngc", label: "Nintendo GameCube"},
  {value: "psx", label: "Sony Playstation"}
];

let valueFromEvent = evt : string => (
                                       evt
                                       |> ReactEventRe.Form.target
                                       |> ReactDOMRe.domElementToObj
                                     )##value;

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {
    name: "",
    players: 0,
    platform: "steam",
    release: 0,
    genre: "",
    websiteUrl: "",
    wikiUrl: "",
    youtubeUrl: "",
    steamUrl: "",
    notes: "",
    author: ""
  },
  reducer: (action, state) =>
    switch action {
    | ChangeName(name) => ReasonReact.Update({...state, name})
    | ChangePlayers(players) => ReasonReact.Update({...state, players})
    | ChangePlatform(platform) => ReasonReact.Update({...state, platform})
    | ChangeGenre(genre) => ReasonReact.Update({...state, genre})
    | ChangeWebsiteUrl(websiteUrl) =>
      ReasonReact.Update({...state, websiteUrl})
    | ChangeWikiUrl(wikiUrl) => ReasonReact.Update({...state, wikiUrl})
    | ChangeYoutubeUrl(youtubeUrl) =>
      ReasonReact.Update({...state, youtubeUrl})
    | ChangeSteamUrl(steamUrl) => ReasonReact.Update({...state, steamUrl})
    | ChangeNotes(notes) => ReasonReact.Update({...state, notes})
    | ChangeAuthor(author) => ReasonReact.Update({...state, author})
    },
  render: ({state, reduce}) => {
    let platformOptions =
      ReasonReact.arrayToElement(
        Array.of_list(
          List.map(
            platform =>
              <option value=platform.value>
                (ReasonReact.stringToElement(platform.label))
              </option>,
            platforms
          )
        )
      );
    MaterialUI.(
      <div className="App-root">
        <header className="App-header">
          <h1>
            (ReasonReact.stringToElement("Reason React with Material UI"))
          </h1>
          <h3>
            (
              ReasonReact.stringToElement(
                "A simple form built with Reason React and Material UI"
              )
            )
          </h3>
        </header>
        <main>
          <form className="App-form" autoComplete="off">
            <TextField
              label="Name"
              value=(`String(state.name))
              onChange=(reduce(e => ChangeName(valueFromEvent(e))))
            />
            <TextField
              label="Players"
              value=(`Int(state.players))
              onChange=(
                reduce(e => ChangePlayers(int_of_string(valueFromEvent(e))))
              )
              _type="number"
            />
            <FormControl>
              <InputLabel htmlFor="platform">
                (ReasonReact.stringToElement("age"))
              </InputLabel>
              <Select
                native=true
                value=(`String(state.platform))
                input=<Input id="platform" />
                onChange=(reduce(e => ChangePlatform(valueFromEvent(e))))>
                platformOptions
              </Select>
            </FormControl>
            <TextField
              label="Genre"
              value=(`String(state.genre))
              onChange=(reduce(e => ChangeGenre(valueFromEvent(e))))
            />
            <TextField
              label="Official website link"
              value=(`String(state.websiteUrl))
              onChange=(reduce(e => ChangeWebsiteUrl(valueFromEvent(e))))
            />
            <TextField
              label="Wikipedia link"
              value=(`String(state.wikiUrl))
              onChange=(reduce(e => ChangeWikiUrl(valueFromEvent(e))))
            />
            <TextField
              label="Youtube link"
              value=(`String(state.youtubeUrl))
              onChange=(reduce(e => ChangeYoutubeUrl(valueFromEvent(e))))
            />
            <TextField
              label="Steam link"
              value=(`String(state.steamUrl))
              onChange=(reduce(e => ChangeSteamUrl(valueFromEvent(e))))
            />
            <TextField
              label="Author"
              value=(`String(state.author))
              onChange=(reduce(e => ChangeAuthor(valueFromEvent(e))))
            />
          </form>
        </main>
      </div>
    );
  }
};