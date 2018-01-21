[%bs.raw {|require('./TextField.css')|}];

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
              <option value=x.value>
                (ReasonReact.stringToElement(x.label))
              </option>,
            data
          )
        )
      );
    MaterialUI.(
      <FormControl>
        <InputLabel htmlFor="platform">
          (ReasonReact.stringToElement(label))
        </InputLabel>
        <Select
          value=(`String(value))
          input=<Input id="platform" />
          onChange=(e => onChange(valueFromEvent(e)))>
          options
        </Select>
      </FormControl>
    );
  }
};