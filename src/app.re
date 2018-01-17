[%bs.raw {|require('./app.css')|}];

type state = {
  name: string,
  players: int,
  platform: string,
  release: int,
  genre: list(string),
  officialWebsiteLink: string,
  wikipediaLink: string,
  videoLink: string,
  steamLink: string
};

type action =
  | ChangeName(string)
  | ChangePlayers(int)
  | ChangePlatform(string);

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
    genre: [],
    officialWebsiteLink: "",
    wikipediaLink: "",
    videoLink: "",
    steamLink: ""
  },
  reducer: (action, state) =>
    switch action {
    | ChangeName(name) => ReasonReact.Update({...state, name})
    | ChangePlayers(players) => ReasonReact.Update({...state, players})
    | ChangePlatform(platform) => ReasonReact.Update({...state, platform})
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
        <div className="App-header">
          <h2> (ReasonReact.stringToElement(state.name)) </h2>
        </div>
        <p className="App-intro">
          (ReasonReact.stringToElement("To get fffff, edit"))
        </p>
        <Paper>
          <form autoComplete="off">
            <TextField
              name="Name"
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
          </form>
        </Paper>
      </div>
    );
  }
};