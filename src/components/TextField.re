[%bs.raw {|require('./TextField.css')|}];

let valueFromEvent = evt : string => (
                                       evt
                                       |> ReactEventRe.Form.target
                                       |> ReactDOMRe.domElementToObj
                                     )##value;

let component = ReasonReact.statelessComponent("TextField");

let make = (~label, ~value, ~onChange, _children) => {
  ...component,
  render: _self =>
    <MaterialUI.FormControl className="TextField">
      <MaterialUI.InputLabel
        _FormControlClasses={"focused": "TextField-focused"}>
        (ReasonReact.stringToElement(label))
      </MaterialUI.InputLabel>
      <MaterialUI.Input
        className="TextField-inputwrapper"
        value
        onChange=(e => onChange(valueFromEvent(e)))
      />
    </MaterialUI.FormControl>
};