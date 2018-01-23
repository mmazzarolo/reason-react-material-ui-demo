[%bs.raw {|require('./Select.css')|}];

let valueFromEvent = evt : string => (
                                       evt
                                       |> ReactEventRe.Form.target
                                       |> ReactDOMRe.domElementToObj
                                     )##value;

let component = ReasonReact.statelessComponent("Select");

type option = {
  value: string,
  label: string
};

let make = (~label, ~data: list(option), ~value, ~onChange, _children) => {
  ...component,
  render: _self => {
    let options =
      ReasonReact.arrayToElement(
        Array.of_list(
          List.map(
            x =>
              <MaterialUI.MenuItem value=(`String(x.value))>
                (ReasonReact.stringToElement(x.label))
              </MaterialUI.MenuItem>,
            data
          )
        )
      );
    <MaterialUI.FormControl className="Select-root">
      <MaterialUI.InputLabel _FormControlClasses={"focused": "Select-focused"}>
        (ReasonReact.stringToElement(label))
      </MaterialUI.InputLabel>
      <MaterialUI.Select
        className="Select-inputwrapper"
        value=(`String(value))
        input=<MaterialUI.Input />
        onChange=(e => onChange(valueFromEvent(e)))>
        options
      </MaterialUI.Select>
    </MaterialUI.FormControl>;
  }
};