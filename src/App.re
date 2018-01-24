[%bs.raw {|require('./App.css')|}];

type state = {
  name: string,
  favoriteAnimal: string
};

type action =
  | ChangeName(string)
  | ChangeFavoriteAnimal(string);

let animals: list(Select.option) = [
  {value: "dog", label: "Dog"},
  {value: "frog", label: "Frog"},
  {value: "sloth", label: "Sloth"}
];

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {name: "", favoriteAnimal: "dog"},
  reducer: (action, state) =>
    switch action {
    | ChangeName(name) => ReasonReact.Update({...state, name})
    | ChangeFavoriteAnimal(favoriteAnimal) =>
      ReasonReact.Update({...state, favoriteAnimal})
    },
  render: ({state, reduce}) =>
    <div className="App-root">
      <header className="App-header">
        <h1>
          (ReasonReact.stringToElement("Reason React"))
          <br />
          (ReasonReact.stringToElement("Material UI"))
        </h1>
        <div className="App-header-separator" />
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
            value=state.name
            onChange=(reduce(e => ChangeName(e)))
          />
          <Select
            label="Favorite Animal"
            value=state.favoriteAnimal
            data=animals
            onChange=(reduce(e => ChangeFavoriteAnimal(e)))
          />
          <div className="App-button-container">
            <Button onClick=(e => Js.log("SENT"))>
              (ReasonReact.stringToElement("Send"))
            </Button>
          </div>
        </form>
      </main>
    </div>
};