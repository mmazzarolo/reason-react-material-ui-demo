[%bs.raw {|require('./TextField.css')|}];

let valueFromEvent = evt : string => (
                                       evt
                                       |> ReactEventRe.Form.target
                                       |> ReactDOMRe.domElementToObj
                                     )##value;

let component = ReasonReact.statelessComponent("TextFieldA");

let make = (~label, ~value, ~onChange, _children) => {
  ...component,
  render: _self =>
    MaterialUI.(
      <FormControl className="TextField">
        <InputLabel _FormControlClasses={"focused": "TextField-focused"}>
          (ReasonReact.stringToElement(label))
        </InputLabel>
        <Input
          className="TextField-inputwrapper"
          value
          onChange=(e => onChange(valueFromEvent(e)))
        />
      </FormControl>
    )
};